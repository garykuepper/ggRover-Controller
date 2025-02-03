#include "Display.h"

// 'ggbytes', 128x64px
const unsigned char Display::ggbytesSplash[] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x0f, 0xfe, 0x07, 0xff, 0x0f, 0xfc, 0x1c, 0x01, 0x9f, 0xff, 0x8f, 0xff, 0x07, 0xfe, 0x00,
	0x00, 0x3f, 0xfe, 0x1f, 0xff, 0x1f, 0xfe, 0x1c, 0x01, 0xdf, 0xff, 0x9f, 0xff, 0x0f, 0xfe, 0x00,
	0x00, 0x3f, 0xfe, 0x1f, 0xff, 0x1f, 0xff, 0x1c, 0x01, 0xdf, 0xff, 0x9f, 0xff, 0x1f, 0xfe, 0x00,
	0x00, 0x7f, 0xfe, 0x3f, 0xff, 0x1f, 0xff, 0x1c, 0x01, 0xdf, 0xff, 0x9f, 0xff, 0x1f, 0xfe, 0x00,
	0x00, 0x7f, 0xfe, 0x3f, 0xff, 0x1f, 0xff, 0x1c, 0x01, 0xdf, 0xff, 0x9f, 0xff, 0x3f, 0xfe, 0x00,
	0x00, 0x70, 0x00, 0x38, 0x00, 0x1c, 0x03, 0x1c, 0x01, 0xc0, 0x60, 0x1c, 0x00, 0x38, 0x00, 0x00,
	0x00, 0x60, 0x00, 0x30, 0x00, 0x1c, 0x03, 0x1c, 0x01, 0xc0, 0x60, 0x1c, 0x00, 0x38, 0x00, 0x00,
	0x00, 0x60, 0x00, 0x30, 0x00, 0x1c, 0x03, 0x1c, 0x01, 0xc0, 0x60, 0x1c, 0x00, 0x38, 0x00, 0x00,
	0x00, 0x60, 0x00, 0x30, 0x00, 0x1c, 0x03, 0x1c, 0x01, 0xc0, 0x60, 0x1c, 0x00, 0x38, 0x00, 0x00,
	0x00, 0x63, 0x00, 0x30, 0x00, 0x1c, 0x07, 0x1c, 0x01, 0x80, 0x60, 0x1c, 0x00, 0x38, 0x00, 0x00,
	0x00, 0x67, 0x80, 0x30, 0x00, 0x1c, 0x07, 0x1c, 0x01, 0x80, 0x60, 0x1c, 0x00, 0x38, 0x00, 0x00,
	0x00, 0x67, 0xfe, 0x31, 0xff, 0x1d, 0xff, 0x1c, 0x01, 0x80, 0x60, 0x1d, 0xfe, 0x3f, 0xfc, 0x00,
	0x00, 0x64, 0xfe, 0x31, 0xff, 0x1d, 0xff, 0x1e, 0x03, 0x80, 0x60, 0x1d, 0xfe, 0x1f, 0xfe, 0x00,
	0x00, 0x6c, 0xfe, 0x31, 0xff, 0x1d, 0xff, 0x0f, 0xff, 0x80, 0x60, 0x1d, 0xfe, 0x1f, 0xfe, 0x00,
	0x00, 0x6c, 0xfe, 0x31, 0xff, 0x1d, 0xff, 0x8f, 0xff, 0x80, 0x60, 0x1d, 0xfe, 0x0f, 0xff, 0x00,
	0x00, 0x64, 0xfe, 0x31, 0xff, 0x1d, 0xff, 0x8f, 0xff, 0x00, 0x60, 0x1d, 0xfe, 0x07, 0xff, 0x00,
	0x00, 0x67, 0x86, 0x30, 0x03, 0x1c, 0x03, 0x87, 0xfe, 0x00, 0x60, 0x1c, 0x00, 0x00, 0x07, 0x00,
	0x00, 0x67, 0x86, 0x30, 0x03, 0x1c, 0x01, 0x83, 0xfc, 0x00, 0x60, 0x1c, 0x00, 0x00, 0x03, 0x00,
	0x00, 0x63, 0x06, 0x30, 0x03, 0x1c, 0x01, 0xc0, 0x70, 0x00, 0x60, 0x1c, 0x00, 0x00, 0x03, 0x00,
	0x00, 0x60, 0x06, 0x30, 0x03, 0x1c, 0x01, 0xc0, 0x70, 0x00, 0x60, 0x1c, 0x00, 0x00, 0x03, 0x00,
	0x00, 0x60, 0x06, 0x30, 0x03, 0x1c, 0x01, 0xc0, 0x70, 0x00, 0x60, 0x1c, 0x00, 0x00, 0x03, 0x00,
	0x00, 0x70, 0x06, 0x38, 0x03, 0x1c, 0x01, 0xc0, 0x70, 0x00, 0x60, 0x1c, 0x00, 0x00, 0x07, 0x00,
	0x00, 0x7f, 0xfe, 0x3f, 0xff, 0x1f, 0xff, 0x80, 0x70, 0x00, 0x60, 0x1f, 0xff, 0x3f, 0xff, 0x00,
	0x00, 0x7f, 0xfe, 0x3f, 0xff, 0x1f, 0xff, 0x80, 0x70, 0x00, 0x60, 0x1f, 0xff, 0x3f, 0xff, 0x00,
	0x00, 0x3f, 0xfe, 0x1f, 0xff, 0x1f, 0xff, 0x80, 0x70, 0x00, 0x60, 0x0f, 0xff, 0x3f, 0xfe, 0x00,
	0x00, 0x3f, 0xfe, 0x1f, 0xff, 0x1f, 0xff, 0x00, 0x70, 0x00, 0x60, 0x0f, 0xff, 0x3f, 0xfe, 0x00,
	0x00, 0x0f, 0xfc, 0x07, 0xff, 0x0f, 0xff, 0x00, 0x70, 0x00, 0x60, 0x03, 0xff, 0x3f, 0xf8, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

Display::Display()
	: disp(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET)
{
}

void Display::init()
{
	if (!disp.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
	{
		Serial.println(F("SSD1306 allocation failed"));
		// while (true);
	}
	// disp.display();
	// delay(2000);
	showSplashScreen();
	disp.clearDisplay();
}

void Display::showText()
{
	disp.clearDisplay();
	disp.setTextSize(2);
	disp.setTextColor(SSD1306_WHITE);
	disp.setCursor(10, 0);
	disp.println(F("Hello, world!"));
	disp.display();
	delay(100);
}

void Display::showDS4(const DS4 &ds4, BatteryMonitor &bm)
{
	disp.clearDisplay();
	disp.setTextSize(1); // Draw 2X-scale text
	disp.setTextColor(SSD1306_WHITE);
	disp.setCursor(10, 0 * lineHeight);
	disp.println((String) "L_Y: " + ds4.l_joystick_y);
	disp.setCursor(10, 1 * lineHeight);
	disp.println((String) "L_X: " + ds4.l_joystick_x);
	disp.setCursor(64, 0 * lineHeight);
	disp.println((String) "R_Y: " + ds4.r_joystick_y);
	disp.setCursor(64, 1 * lineHeight);
	disp.println((String) "R_X: " + ds4.r_joystick_x);
	disp.setCursor(10, 2 * lineHeight);
	disp.println((String) "L1: " + ds4.button_l1);
	disp.setCursor(10, 3 * lineHeight);
	disp.println((String) "L2: " + ds4.l2);
	disp.setCursor(64, 2 * lineHeight);
	disp.println((String) "R1: " + ds4.button_r1);
	disp.setCursor(64, 3 * lineHeight);
	disp.println((String) "R2: " + ds4.r2);
	disp.setCursor(120, 0 * lineHeight);
	disp.println((String)ds4.button_x);
	disp.setCursor(120, 1 * lineHeight);
	disp.println((String)ds4.button_circle);
	disp.setCursor(120, 2 * lineHeight);
	disp.println((String)ds4.button_square);
	disp.setCursor(120, 3 * lineHeight);
	disp.println((String)ds4.button_triangle);
	disp.setCursor(10, 4 * lineHeight);

	disp.println((String)ds4.battery);

	disp.setCursor(64, 4 * lineHeight);
	disp.println((String)bm.getBatteryLevel() + "V");
	disp.setCursor(64, 5 * lineHeight);
	disp.println((String)round(bm.getBatteryPercentage()) + "%");

	disp.display();
}
void Display::showSplashScreen()
{
	disp.clearDisplay();
	disp.drawBitmap(0, 0, ggbytesSplash, SCREEN_WIDTH, SCREEN_HEIGHT, SSD1306_WHITE);
	disp.display();
	delay(3000); // Show the splash screen for 3 seconds
}
