/*
 * ConfigSet1.h
 *
 *  Created on: Apr 18, 2018
 *      Author: mpand
 */

#ifndef LIBRARIES_CONFIGS_CONFIGSET3_H_
#define LIBRARIES_CONFIGS_CONFIGSET3_H_
#include <ConfigItem.h>

	// Clock config values
	BooleanConfigItem time_or_date("time_or_date", true);	// time
	ByteConfigItem date_format("date_format", 1);			// mm-dd-yy, dd-mm-yy, yy-mm-dd
	BooleanConfigItem hour_format("hour_format", false);	// 12/24 hour
	BooleanConfigItem leading_zero("leading_zero", true);	//
	ByteConfigItem fading("fading", 1);
	ByteConfigItem colons("colons", 1);					// flashing, on , off
	ByteConfigItem display_on("display_on", 6);
	ByteConfigItem display_off("display_off", 22);
	StringConfigItem time_url("time_url", 80, String("EST5EDT,M3.2.0,M11.1.0"));

	// LED config values
	ByteConfigItem hue("hue", 0);
	ByteConfigItem saturation("saturation", 215);
	BooleanConfigItem backlight("backlight", true);
	BooleanConfigItem underlight("underlight", false);
	BooleanConfigItem hue_cycling("hue_cycling", true);
	ByteConfigItem led_scale("led_scale", 127);
	ByteConfigItem underlight_scale("underlight_scale", 127);
	IntConfigItem cycle_time("cycle_time", 120);

	// Extra config values
	ByteConfigItem show_date("show_date", 1);	// 1 = show date every minute
	ByteConfigItem out_effect("out_effect", 1);	// 1 = slide display to the left
	ByteConfigItem in_effect("in_effect", 1);	// 1 = slide display to the left
	BooleanConfigItem display("display", true);	// true == clock
	IntConfigItem test("test", 0);
	ByteConfigItem test_speed("test_speed", 60);	// ticks per minute 0 to 60
	IntConfigItem reset_time("reset_time", 2800);	// Length of reset pulse in uS
	IntConfigItem set_time("set_time", 120);	// Length of set pulse in uS
	BooleanConfigItem hv("hv", true);
	ByteConfigItem mov_delay("mov_delay", 0);
	ByteConfigItem mov_src("mov_src", 0);

	// Alexa config values
	StringConfigItem date_name("date_name", 20, String("date"));
	StringConfigItem backlight_name("backlight_name", 20, String("backlight"));
	StringConfigItem clock_name("clock_name", 20, String("clock"));
	StringConfigItem test_name("test_name", 20, String("test"));
	StringConfigItem cycling_name("cycling_name", 20, String("hue cycling"));
	StringConfigItem twelve_hour_name("twelve_hour_name", 20, String("12 hour"));
	StringConfigItem zero_name("zero_name", 20, String("leading zero"));

	// Sync config values
	IntConfigItem sync_port("sync_port", 4920);
	ByteConfigItem sync_role("sync_role", 0);	// 0 = none, 1 = master, 2 = slave

	BaseConfigItem *clockSet[] = {
		// Clock
		&time_or_date,
		&date_format,
		&hour_format,
		&leading_zero,
		&fading,
		&colons,
		&display_on,
		&display_off,
		&time_url,
		0
	};

	BaseConfigItem *ledSet[] = {
		// LEDs
		&cycle_time,
		&hue,
		&saturation,
		&led_scale,
		&underlight_scale,
		&backlight,
		&underlight,
		&hue_cycling,
		0
	};

	BaseConfigItem *extraSet[] = {
		// Extra
		&show_date,
		&out_effect,
		&in_effect,
		&display,
		&test,
		&test_speed,
		&reset_time,
		&set_time,
		&hv,
		&mov_delay,
		&mov_src,
		0
	};

	BaseConfigItem *syncSet[] = {
		// Sync
		&sync_port,
		&sync_role,
		0
	};

	CompositeConfigItem clockConfig("clock", 0, clockSet);
	CompositeConfigItem ledConfig("leds", 0, ledSet);
	CompositeConfigItem extraConfig("extra", 0, extraSet);
	CompositeConfigItem syncConfig("sync", 0, syncSet);

	BaseConfigItem *configSet[] = {
		&clockConfig,
		&ledConfig,
		&extraConfig,
		&syncConfig,
		0
	};

	CompositeConfigItem config("set3", 0, configSet);

#endif /* LIBRARIES_CONFIGS_CONFIGSET3_H_ */
