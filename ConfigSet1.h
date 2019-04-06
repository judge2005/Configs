/*
 * ConfigSet1.h
 *
 *  Created on: Apr 18, 2018
 *      Author: mpand
 */

#ifndef LIBRARIES_CONFIGS_CONFIGSET1_H_
#define LIBRARIES_CONFIGS_CONFIGSET1_H_
#include <ConfigItem.h>

	// Clock config values
	BooleanConfigItem time_or_date("time_or_date", true);
	ByteConfigItem date_format("date_format", 1);
	BooleanConfigItem time_format("time_format", false);
	BooleanConfigItem hour_format("hour_format", false);
	ByteConfigItem fading("fading", 1);
	ByteConfigItem indicator("indicator", 1);
	BooleanConfigItem scrollback("scrollback", true);
	IntConfigItem digits_on("digits_on", 1500);
	ByteConfigItem display_on("display_on", 6);
	ByteConfigItem display_off("display_off", 22);
	StringConfigItem time_url("time_url", 80, String("http://time.nixies.us/getTime/America/New_York"));

	// LED config values
	ByteConfigItem hue("hue", 0);
	ByteConfigItem saturation("saturation", 215);
	BooleanConfigItem backlight("backlight", true);
	BooleanConfigItem hue_cycling("hue_cycling", true);
	ByteConfigItem led_scale("led_scale", 127);
	IntConfigItem cycle_time("cycle_time", 120);

	// Extra config values
	BooleanConfigItem dimming("dimming", true);
	BooleanConfigItem display("display", true);	// true == clock
	BooleanConfigItem hv("hv", true);
	ByteConfigItem voltage("voltage", 176);
	IntConfigItem digit("digit", 0);
	ByteConfigItem count_speed("count_speed", 60);	// ticks per minute 0 to 60
	StringConfigItem pin_order("pin_order", 13, "0123456789ab");
	IntConfigItem pwm_freq("pwm_freq", 8000);
	ByteConfigItem mov_delay("mov_delay", 0);

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
		&time_format,
		&hour_format,
		&fading,
		&indicator,
		&scrollback,
		&digits_on,
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
		&backlight,
		&hue_cycling,
		0
	};

	BaseConfigItem *extraSet[] = {
		// Extra
		&dimming,
		&display,
		&hv,
		&voltage,
		&digit,
		&count_speed,
		&pin_order,
		&pwm_freq,
		&mov_delay,
		0
	};

	BaseConfigItem *upsSet[] = {
		// UPS
		&charge_rate,
		&lpm,
		&wakeup_time,
		&sensitivity
	};

	BaseConfigItem *syncSet[] = {
		// Sync
		&sync_port,
		&sync_role
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

	CompositeConfigItem config("set1", 0, configSet);




#endif /* LIBRARIES_CONFIGS_CONFIGSET1_H_ */
