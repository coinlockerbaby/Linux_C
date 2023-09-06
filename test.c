#include <stdio.h>

int main() {
    char json[] = "{\"MQTT\": \"0\", \"Weather\": \"Cloudy\", \"time\": \"2023-09-03 23:55:14\"}";

    char mqtt[10];
    char weather[20];
    char time[20];

    sscanf(json, "{\"MQTT\": \"%[^\"]\", \"Weather\": \"%[^\"]\", \"time\": \"%[^\"]\"}", mqtt, weather, time);

    printf("MQTT: %s\n", mqtt);
    printf("Weather: %s\n", weather);
    printf("Time: %s\n", time);

    return 0;
}