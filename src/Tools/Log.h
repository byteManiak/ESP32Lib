/*
	Author: bitluni 2019
	License: 
	Creative Commons Attribution ShareAlike 4.0
	https://creativecommons.org/licenses/by-sa/4.0/
	
	For further details check out: 
		https://youtube.com/bitlunislab
		https://github.com/bitluni
		http://bitluni.net
*/
#pragma once
#include <esp_log.h>

#define DEBUG_PRINTLN(a) ESP_LOGI("debug", a)
#define DEBUG_PRINT(a) ESP_LOGI("debug", a)
#define DEBUG_PRINTLNF(a, f) ESP_LOGI("debug", a, f)
#define DEBUG_PRINTF(a, f) ESP_LOGI("debug", a, f)
/*
#define DEBUG_PRINTLN(a) ;
#define DEBUG_PRINT(a) ;
#define DEBUG_PRINTLNF(a, f) ;
#define DEBUG_PRINTF(a, f) ;
*/
#define ERROR(a) ESP_LOGE("debug", a)
