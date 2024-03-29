/*
 * ConfigSet1.h
 *
 *  Created on: Apr 18, 2018
 *      Author: mpand
 */

#ifndef LIBRARIES_CONFIGS_CONFIGSET2_H_
#define LIBRARIES_CONFIGS_CONFIGSET2_H_
#include <ConfigItem.h>

	// Clock config values
	BooleanConfigItem time_or_date("time_or_date", true);	// time
	ByteConfigItem date_format("date_format", 2);			// mm-dd-yy, dd-mm-yy, yy-mm-dd
	BooleanConfigItem hour_format("hour_format", false);	// 12/24 hour
	BooleanConfigItem leading_zero("leading_zero", true);	//
	ByteConfigItem fading("fading", 1);
	ByteConfigItem colons("colons", 3);					// off, on , flashing, AM/PM
	ByteConfigItem display_on("display_on", 6);
	ByteConfigItem display_off("display_off", 22);
	StringConfigItem time_url("time_url", 80, String("EST5EDT,M3.2.0,M11.1.0"));
	StringConfigItem time_url2("time_url2", 80, String("GMT0BST,M3.5.0/1,M10.5.0"));

	// LED config values
	ByteConfigItem hue("hue", 0);
	ByteConfigItem saturation("saturation", 215);
	BooleanConfigItem backlight("backlight", false);
	BooleanConfigItem underlight("underlight", false);
	BooleanConfigItem hue_cycling("hue_cycling", true);
	ByteConfigItem led_scale("led_scale", 127);
	ByteConfigItem underlight_scale("underlight_scale", 127);
	IntConfigItem cycle_time("cycle_time", 120);
	BooleanConfigItem sec_hue("sec_hue", false);
	BooleanConfigItem sec_sat("sec_sat", false);
	BooleanConfigItem sec_val("sec_val", false);
	BooleanConfigItem brightness_gamma("b_gamma", true);

	// Extra config values
	BooleanConfigItem dimming("dimming", true);
	ByteConfigItem show_date("show_date", 1);	// 1 = show date every minute
	ByteConfigItem out_effect("out_effect", 1);	// 1 = slide display to the left
	ByteConfigItem in_effect("in_effect", 1);	// 1 = slide display to the left
	BooleanConfigItem display("display", true);	// true == clock
	ByteConfigItem test_speed("test_speed", 60);	// ticks per minute 0 to 60
	BooleanConfigItem hv("hv", true);
	ByteConfigItem voltage("voltage", 176);
	ByteConfigItem warming("warming", 1);
	ByteConfigItem mov_delay("mov_delay", 0);
	ByteConfigItem mov_src("mov_src", 0);

	// Events config values (basically wav file names without the .wav)
	StringConfigItem tick_name("tick_name", 20, String("Tick"));
	BooleanConfigItem tick_on("tick_on", true);
	ByteConfigItem tick_volume("tick_volume", 25);	// percentage
	StringConfigItem chime_name("chime_name", 20, String("Chime"));
	BooleanConfigItem chime_on("chime_on", true);
	ByteConfigItem chime_volume("chime_volume", 25);	// percentage
	StringConfigItem strike_name("strike_name", 20, String("Strike"));
	BooleanConfigItem strike_on("strike_on", true);
	ByteConfigItem strike_volume("strike_volume", 25);	// percentage
	StringConfigItem alarm_name("alarm_name", 20, String("Alarm"));
	StringConfigItem alarm_time("alarm_time", 6, "18:00");
	BooleanConfigItem alarm_on("alarm_on", false);
	ByteConfigItem alarm_volume("alarm_volume", 25);	// percentage

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
		&time_url2,
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
		&sec_hue,
		&sec_sat,
		&sec_val,
		&brightness_gamma,
		0
	};

	BaseConfigItem *extraSet[] = {
		// Extra
		&dimming,
		&show_date,
		&out_effect,
		&in_effect,
		&display,
		&test_speed,
		&hv,
		&voltage,
		&warming,
		&mov_delay,
		&mov_src,
		0
	};

	BaseConfigItem *eventsSet[] = {
		// Events
		&tick_name,
		&tick_on,
		&tick_volume,
		&chime_name,
		&chime_on,
		&chime_volume,
		&strike_name,
		&strike_on,
		&strike_volume,
		&alarm_name,
		&alarm_time,
		&alarm_on,
		&alarm_volume,
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
	CompositeConfigItem eventsConfig("events", 0, eventsSet);
	CompositeConfigItem syncConfig("sync", 0, syncSet);

	BaseConfigItem *configSet[] = {
		&clockConfig,
		&ledConfig,
		&extraConfig,
		&eventsConfig,
		&syncConfig,
		0
	};

	CompositeConfigItem config("set2", 0, configSet);

#endif /* LIBRARIES_CONFIGS_CONFIGSET2_H_ */
