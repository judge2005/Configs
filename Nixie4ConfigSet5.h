/*
 * ConfigSet1.h
 *
 *  Created on: Apr 18, 2018
 *      Author: mpand
 */

#ifndef LIBRARIES_CONFIGS_CONFIGSET5_H_
#define LIBRARIES_CONFIGS_CONFIGSET5_H_
#include <ConfigItem.h>

	// Clock config values
	BooleanConfigItem time_or_date("time_or_date", true);	// time
	ByteConfigItem date_format("date_format", 1);			// mm-dd-yy, dd-mm-yy, yy-mm-dd
	BooleanConfigItem hour_format("hour_format", false);	// 12/24 hour
	BooleanConfigItem leading_zero("leading_zero", true);	//
	ByteConfigItem fading("fading", 0);
	ByteConfigItem colons("colons", 1);					// flashing, on , off
	ByteConfigItem display_on("display_on", 6);
	ByteConfigItem display_off("display_off", 22);
	StringConfigItem time_url("time_url", 80, String("EST5EDT,M3.2.0,M11.1.0"));

	// LED config values
	ByteConfigItem hue("hue", 0);
	ByteConfigItem saturation("saturation", 215);
	BooleanConfigItem backlight("backlight", true);
	BooleanConfigItem seconds("seconds", true);
	BooleanConfigItem hue_cycling("hue_cycling", true);
	ByteConfigItem led_scale("led_scale", 255);
	ByteConfigItem seconds_scale("seconds_scale", 127);
	IntConfigItem cycle_time("cycle_time", 132);
	BooleanConfigItem sec_hue("sec_hue", false);
	BooleanConfigItem sec_sat("sec_sat", false);
	BooleanConfigItem sec_val("sec_val", false);

	// Extra config values
	BooleanConfigItem dimming("dimming", true);
	ByteConfigItem show_date("show_date", 1);	// 1 = show date every minute
	ByteConfigItem out_effect("out_effect", 1);	// 1 = slide display to the left
	ByteConfigItem in_effect("in_effect", 1);	// 1 = slide display to the left
	BooleanConfigItem display("display", true);	// true == clock
	ByteConfigItem test_speed("test_speed", 60);	// ticks per minute 0 to 60
	BooleanConfigItem hv("hv", true);
	ByteConfigItem voltage("voltage", 176);
	ByteConfigItem mov_delay("mov_delay", 0);
	ByteConfigItem mov_src("mov_src", 0);

	// UPS config values
	ByteConfigItem charge_rate("charge_rate", 0);	// 0 = Auto
	BooleanConfigItem lpm("lpm", true);	// Low power mode - sleep when on battery
	ByteConfigItem wakeup_time("wakeup_time", 25);	// How long to stay on during lpm
	ByteConfigItem sensitivity("sensitivity", 40);	// Tap-detection sensitivity

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
		&seconds_scale,
		&backlight,
		&seconds,
		&hue_cycling,
		&sec_hue,
		&sec_sat,
		&sec_val,
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
		&mov_delay,
		&mov_src,
		0
	};

	BaseConfigItem *upsSet[] = {
		// UPS
		&charge_rate,
		&lpm,
		&wakeup_time,
		&sensitivity,
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
	CompositeConfigItem upsConfig("ups", 0, upsSet);
	CompositeConfigItem syncConfig("sync", 0, syncSet);

	BaseConfigItem *configSet[] = {
		&clockConfig,
		&ledConfig,
		&extraConfig,
		&upsConfig,
		&syncConfig,
		0
	};

	CompositeConfigItem config("set5", 0, configSet);

#endif /* LIBRARIES_CONFIGS_CONFIGSET5_H_ */
