#include <stdio.h>
#include <stdarg.h>

//when declare enum, eles will have value start 0 to +1
typedef enum {
    LOG_LEVEL_ERROR,    //0
    LOG_LEVEL_WARNING,  //1
    LOG_LEVEL_INFO,     //2
    LOG_LEVEL_DEBUG     //3
} log_level_t;

#define NRF_LOG_ENABLED 1
#define NRF_LOG_DEFAULT_LEVEL LOG_LEVEL_DEBUG

#define ENF_OF_LINE_STRING  "\r\n"

#define LOG_ERROR(...)   LOG_INTERNAL_ERROR(__VA_ARGS__)
#define LOG_WARNING(...) LOG_INTERNAL_WARNING(__VA_ARGS__)
#define LOG_INFO(...)    LOG_INTERNAL_INFO(__VA_ARGS__)
#define LOG_DEBUG(...)   LOG_INTERNAL_DEBUG(__VA_ARGS__)

#define LOG_INTERNAL_ERROR(...)   LOG_INTERNAL_MODULE(LOG_LEVEL_ERROR, __VA_ARGS__)
#define LOG_INTERNAL_WARNING(...) LOG_INTERNAL_MODULE(LOG_LEVEL_WARNING, __VA_ARGS__)
#define LOG_INTERNAL_INFO(...)    LOG_INTERNAL_MODULE(LOG_LEVEL_INFO, __VA_ARGS__)
#define LOG_INTERNAL_DEBUG(...)   LOG_INTERNAL_MODULE(LOG_LEVEL_DEBUG, __VA_ARGS__)

#define LOG_INTERNAL_MODULE(level, ...) \
    do { \
        if (NRF_LOG_ENABLED && (level <= NRF_LOG_DEFAULT_LEVEL)) { \
            printf(__VA_ARGS__); \
        } \
    } while(0)

int main() {
    LOG_ERROR("This is an error message: %d\n", LOG_LEVEL_ERROR);
    LOG_WARNING("This is a warning message: %d\n", LOG_LEVEL_WARNING);
    LOG_INFO("This is an info message: %d\n", LOG_LEVEL_INFO);
    LOG_DEBUG("This is a debug message: %d\n", LOG_LEVEL_DEBUG);
    
    return 0;
}
