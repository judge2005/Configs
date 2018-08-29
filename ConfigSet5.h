/*
 * ConfigSet5.h
 *
 *  Created on: Apr 18, 2018
 *      Author: mpand
 */

#ifndef LIBRARIES_CONFIGS_CONFIGSET5_H_
#define LIBRARIES_CONFIGS_CONFIGSET5_H_

#include <ConfigItem.h>

	// Clock config values
	BooleanConfigItem time_or_date("time_or_date", true);
	ByteConfigItem date_format("date_format", 1);
	BooleanConfigItem time_format("time_format", false);
	BooleanConfigItem hour_format("hour_format", false);
	ByteConfigItem fading("fading", 3);
	ByteConfigItem indicator("indicator", 0);
	BooleanConfigItem scrollback("scrollback", true);
	IntConfigItem digits_on("digits_on", 1500);
	ByteConfigItem display_on("display_on", 6);
	ByteConfigItem display_off("display_off", 22);
	StringConfigItem time_url("time_url", 80, String("http://time.nixies.us/getTime/America/New_York"));

	// LED config values
	ByteConfigItem hue("hue", 100);
	ByteConfigItem saturation("saturation", 255);
	BooleanConfigItem backlight("backlight", true);
	BooleanConfigItem hue_cycling("hue_cycling", false);
	ByteConfigItem led_scale("led_scale", 255);
	IntConfigItem cycle_time("cycle_time", 60);

	// Extra config values
	BooleanConfigItem dimming("dimming", true);
	BooleanConfigItem display("display", false);	// true == clock
	BooleanConfigItem hv("hv", true);
	ByteConfigItem voltage("voltage", 176);
	IntConfigItem digit("digit", 0);
	ByteConfigItem count_speed("count_speed", 60);	// ticks per minute 0 to 60

	// UPS config values
	ByteConfigItem charge_rate("charge_rate", 0);	// 0 = Auto
	BooleanConfigItem lpm("lpm", false);	// Low power mode - sleep when on battery
	ByteConfigItem wakeup_time("wakeup_time", 25);	// How long to stay on during lpm
	ByteConfigItem sensitivity("sensitivity", 40);	// Tap-detection sensitivity

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
		0
	};

	BaseConfigItem *upsSet[] = {
		// UPS
		&charge_rate,
		&lpm,
		&wakeup_time,
		&sensitivity
	};

	CompositeConfigItem clockConfig("clock", 0, clockSet);
	CompositeConfigItem ledConfig("leds", 0, ledSet);
	CompositeConfigItem extraConfig("extra", 0, extraSet);
	CompositeConfigItem upsConfig("ups", 0, upsSet);

	BaseConfigItem *configSet[] = {
		// Clock
		&clockConfig,
		&ledConfig,
		&extraConfig,
		&upsConfig,
		0
	};

	CompositeConfigItem config("set5", 0, configSet);



#endif /* LIBRARIES_CONFIGS_CONFIGSET5_H_ */
