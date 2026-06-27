idf_component_register(SRCS take_picture.c socket_utils.c
                        PRIV_INCLUDE_DIRS .
                        PRIV_REQUIRES nvs_flash esp_psram esp_wifi esp_event esp_netif lwip) 
