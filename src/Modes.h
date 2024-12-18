//******************************************************************************
// Modes.h
//******************************************************************************

#ifndef MODES_H
#define MODES_H

typedef enum eMode : uint8_t
{
    MODE_TIME,				// 0
#ifdef SHOW_MODE_AMPM
    MODE_AMPM,				// 1
#endif
#ifdef SHOW_MODE_SECONDS
    MODE_SECONDS,			// 2 if SHOW_MODE_AMPM is set - 1 if not set and so on...
#endif
#ifdef SHOW_MODE_WEEKDAY
    MODE_WEEKDAY,			// 3 if...
#endif
#ifdef SHOW_MODE_DATE
    MODE_DATE,				// 4
#endif
#if defined(SHOW_MODE_SUNRISE_SUNSET) && defined(WEATHER)
    MODE_SUNRISE, 			// 5
    MODE_SUNSET, 			// 6
#endif
#ifdef SHOW_MODE_MOONPHASE
    MODE_MOONPHASE,			// 7
#endif
#if defined(RTC_BACKUP) || defined(SENSOR_DHT22)
    MODE_TEMP,				// 8
#endif
#ifdef SENSOR_DHT22
    MODE_HUMIDITY,			// 9
#endif
#ifdef WEATHER
    MODE_EXT_TEMP,			// 10
    MODE_EXT_HUMIDITY,		// 11
#endif
#ifdef BUZZER
    MODE_TIMER,				// 12
#endif
#ifdef SHOW_MODE_TEST
    MODE_TEST,				// 13
    MODE_RED,				// 14
    MODE_GREEN,				// 15
    MODE_BLUE,				// 16
    MODE_WHITE,				// 17
#endif
    MODE_COUNT,				// 18
    MODE_BLANK,				// 19
    MODE_FEED				// 20
} Mode;

// Overload the ControlType++ operator.
inline Mode& operator++(Mode& eDOW, int)
{
    const uint8_t i = static_cast<uint8_t>(eDOW) + 1;
    eDOW = static_cast<Mode>((i) % MODE_COUNT);
    return eDOW;
}

enum eTransition
{
    TRANSITION_NORMAL, // 0
    TRANSITION_MOVEUP, // 1
    TRANSITION_FADE    // 2
};

#endif
