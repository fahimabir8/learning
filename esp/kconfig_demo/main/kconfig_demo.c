#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "say_hello.h"

static const uint32_t sleep_time_ms = 1000;

static const char *TAG = "kconfig_demo";

void app_main(void)
{
    while (1) {
#ifdef CONFIG_SAY_HELLO
        say_hello();
#endif
        printf("log messages: \n");
        ESP_LOGE(TAG, "Error");
        ESP_LOGW(TAG, "Warning");
        ESP_LOGI(TAG, "Info");
        ESP_LOGD(TAG, "Debug");
        ESP_LOGV(TAG, "Verbose");

        vTaskDelay(sleep_time_ms / portTICK_PERIOD_MS);
    }
}
