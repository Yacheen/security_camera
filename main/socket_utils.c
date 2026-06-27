#include "esp_log.h"
#include "lwip/sockets.h"
#include <errno.h>
int send_all_as_chunks(int sock, uint8_t *buf, size_t buf_size, struct sockaddr_in dest_addr)
{
    int remaining_bytes_to_send = buf_size;
    ESP_LOGE("example:take_picture", "Remaining bytes: %d", remaining_bytes_to_send);
    int bytes_sent = 0;
    while (remaining_bytes_to_send != 0)
    {
        if (remaining_bytes_to_send > 40000) {
            ESP_LOGI("example:take_picture", "Remaining bytes: %d", remaining_bytes_to_send);
            int err = sendto(sock, &buf[bytes_sent], 40000, 0, (struct sockaddr*)&dest_addr, sizeof(dest_addr));
            if (err < 0) {
                return err;
            }
            bytes_sent += 40000;
            remaining_bytes_to_send -= 40000;
        } 
        else {
            ESP_LOGI("example:take_picture", "Remaining bytes: %d", remaining_bytes_to_send);
            int err = sendto(sock, &buf[bytes_sent], remaining_bytes_to_send, 0, (struct sockaddr*)&dest_addr,  sizeof(dest_addr));
            if (err < 0) {
                return err;
            }
            return 0;
        }
    }
    return -1;
}
