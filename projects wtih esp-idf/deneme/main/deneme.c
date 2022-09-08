#include <driver/gpio.h>
#include <driver/uart.h>
// Include FreeRTOS for delay
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "driver/temperature_sensor.h"
#include "esp_log.h"
#include <string.h>

static const char *TAG = "temperature";

int app_main() {
    
    int loop;
    float tsens_value;
    
    uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };
    uart_driver_install(UART_NUM_1, 2048, 0, 0, NULL, 0);
    uart_param_config(UART_NUM_1, &uart_config);
    uart_set_pin(UART_NUM_1, 10, 9, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);

    loop = 50;
    ESP_LOGI(TAG, "Install temperature sensor, expected temp ranger range: 10~50 ℃");
    temperature_sensor_handle_t temp_handle = NULL;
    temperature_sensor_config_t temp_sensor = {
        .range_min = 10,
        .range_max = 50,
    };
    ESP_ERROR_CHECK(temperature_sensor_install(&temp_sensor, &temp_handle));
    
    ESP_LOGI(TAG, "Enable temperature sensor");
    ESP_ERROR_CHECK(temperature_sensor_enable(temp_handle));

    ESP_LOGI(TAG, "Read temperature");
    while (loop--) {
        ESP_ERROR_CHECK(temperature_sensor_get_celsius(temp_handle, &tsens_value));
        uart_write_bytes(UART_NUM_1, tsens_value, 20);
        vTaskDelay(100 / portTICK_RATE_MS);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
