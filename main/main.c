#include <stdio.h>
#include <esp_err.h>
#include <esp_log.h>

// Обязательно объявляем тег для логирования
static const char *TAG = "main";

void app_main(void) 
{
    // Исправлено: добавлен символ подчеркивания в макрос ESP_LOGI
    ESP_LOGI(TAG, "Hello, World!"); 
}
