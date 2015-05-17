// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

// Created by Peter Buelow on May 15, 2015

#ifndef __PINMUX_H__
#define __PINMUX_H__

#include <string.h>
#include <stdio.h>

int pin_to_gpio(char *str, int *a, int *b)
{
	if (!str) {
		fprintf(stderr, "%s: str is NULL\n", __FUNCTION__);
		return -1;
	}

	if (!a) {
		fprintf(stderr, "%s: a is NULL\n", __FUNCTION__);
		return -1;
	}

	if (!b) {
		fprintf(stderr, "%s: b is NULL\n", __FUNCTION__);
		return -1;
	}

	if (strcmp(str, "P9_11") == 0) {
		*a = 0;
		*b = 30;
		return 1;
	}
	if (strcmp(str, "P9_12") == 0) {
		*a = 1;
		*b = 28;
		return 2;
	}
	if (strcmp(str, "P9_13") == 0) {
		*a = 0;
		*b = 31;
		return 3;
	}
	if (strcmp(str, "P9_14") == 0) {
		*a = 1;
		*b = 18;
		return 4;
	}
	if (strcmp(str, "P9_15") == 0) {
		*a = 1;
		*b = 16;
		return 5;
	}
	if (strcmp(str, "P9_16") == 0) {
		*a = 1;
		*b = 19;
		return 6;
	}
	if (strcmp(str, "P9_17") == 0) {
		*a = 0;
		*b = 5;
		return 7;
	}
	if (strcmp(str, "P9_18") == 0) {
		*a = 0;
		*b = 4;
		return 8;
	}
	if (strcmp(str, "P9_19") == 0) {
		*a = 0;
		*b = 13;
		return 9;
	}
	if (strcmp(str, "P9_20") == 0) {
		*a = 0;
		*b = 12;
		return 10;
	}
	if (strcmp(str, "P9_21") == 0) {
		*a = 0;
		*b = 3;
		return 11;
	}
	if (strcmp(str, "P9_22") == 0) {
		*a = 0;
		*b = 2;
		return 12;
	}
	if (strcmp(str, "P9_23") == 0) {
		*a = 1;
		*b = 17;
		return 13;
	}
	if (strcmp(str, "P9_24") == 0) {
		*a = 0;
		*b = 15;
		return 14;
	}
	if (strcmp(str, "P9_25") == 0) {
		*a = 3;
		*b = 21;
		return 15;
	}
	if (strcmp(str, "P9_26") == 0) {
		*a = 0;
		*b = 14;
		return 16;
	}
	if (strcmp(str, "P9_27") == 0) {
		*a = 3;
		*b = 19;
		return 17;
	}
	if (strcmp(str, "P9_28") == 0) {
		*a = 3;
		*b = 17;
		return 18;
	}
	if (strcmp(str, "P9_29") == 0) {
		*a = 3;
		*b = 15;
		return 19;
	}
	if (strcmp(str, "P9_30") == 0) {
		*a = 3;
		*b = 16;
		return 20;
	}
	if (strcmp(str, "P9_31") == 0) {
		*a = 3;
		*b = 14;
		return 21;
	}
	if (strcmp(str, "P9_41") == 0) {
		*a = 0;
		*b = 20;
		return 22;
	}
	if (strcmp(str, "P9_42") == 0) {
		*a = 0;
		*b = 7;
		return 23;
	}
	if (strcmp(str, "UART4_RXD") == 0) {
		*a = 0;
		*b = 30;
		return 24;
	}
	if (strcmp(str, "UART4_TXD") == 0) {
		*a = 0;
		*b = 31;
		return 25;
	}
	if (strcmp(str, "EHRPWM1AD") == 0) {
		*a = 1;
		*b = 18;
		return 26;
	}
	if (strcmp(str, "EHRPWM1BD") == 0) {
		*a = 1;
		*b = 19;
		return 27;
	}
	if (strcmp(str, "I2C1_SCLD") == 0) {
		*a = 0;
		*b = 5;
		return 28;
	}
	if (strcmp(str, "I2C1_SDAD") == 0) {
		*a = 0;
		*b = 4;
		return 29;
	}
	if (strcmp(str, "I2C2_SCLD") == 0) {
		*a = 0;
		*b = 13;
		return 30;
	}
	if (strcmp(str, "I2C2_SDAD") == 0) {
		*a = 0;
		*b = 12;
		return 31;
	}
	if (strcmp(str, "UART2_TXD") == 0) {
		*a = 0;
		*b = 3;
		return 32;
	}
	if (strcmp(str, "UART2_RXD") == 0) {
		*a = 0;
		*b = 2;
		return 33;
	}
	if (strcmp(str, "UART1_TXD") == 0) {
		*a = 0;
		*b = 15;
		return 34;
	}
	if (strcmp(str, "UART1_RXD") == 0) {
		*a = 0;
		*b = 14;
		return 35;
	}
	if (strcmp(str, "SPI1_CS0D") == 0) {
		*a = 3;
		*b = 17;
		return 36;
	}
	if (strcmp(str, "SPI1_D0") == 0) {
		*a = 3;
		*b = 15;
		return 37;
	}
	if (strcmp(str, "SPI1_D1") == 0) {
		*a = 3;
		*b = 16;
		return 38;
	}
	if (strcmp(str, "SPI1_SCLK") == 0) {
		*a = 3;
		*b = 14;
		return 39;
	}
	if (strcmp(str, "CLKOUT2") == 0) {
		*a = 0;
		*b = 20;
		return 40;
	}
	if (strcmp(str, "30") == 0) {
		*a = 0;
		*b = 30;
		return 41;
	}
	if (strcmp(str, "60") == 0) {
		*a = 1;
		*b = 28;
		return 42;
	}
	if (strcmp(str, "31") == 0) {
		*a = 0;
		*b = 31;
		return 43;
	}
	if (strcmp(str, "50") == 0) {
		*a = 1;
		*b = 18;
		return 44;
	}
	if (strcmp(str, "48") == 0) {
		*a = 1;
		*b = 16;
		return 45;
	}
	if (strcmp(str, "51") == 0) {
		*a = 1;
		*b = 19;
		return 46;
	}
	if (strcmp(str, "5") == 0) {
		*a = 0;
		*b = 5;
		return 47;
	}
	if (strcmp(str, "4") == 0) {
		*a = 0;
		*b = 4;
		return 48;
	}
	if (strcmp(str, "13") == 0) {
		*a = 0;
		*b = 13;
		return 49;
	}
	if (strcmp(str, "12") == 0) {
		*a = 0;
		*b = 12;
		return 50;
	}
	if (strcmp(str, "3") == 0) {
		*a = 0;
		*b = 3;
		return 51;
	}
	if (strcmp(str, "2") == 0) {
		*a = 0;
		*b = 2;
		return 52;
	}
	if (strcmp(str, "49") == 0) {
		*a = 1;
		*b = 17;
		return 53;
	}
	if (strcmp(str, "15") == 0) {
		*a = 0;
		*b = 15;
		return 54;
	}
	if (strcmp(str, "117") == 0) {
		*a = 3;
		*b = 21;
		return 55;
	}
	if (strcmp(str, "14") == 0) {
		*a = 0;
		*b = 14;
		return 56;
	}
	if (strcmp(str, "115") == 0) {
		*a = 3;
		*b = 19;
		return 57;
	}
	if (strcmp(str, "113") == 0) {
		*a = 3;
		*b = 17;
		return 58;
	}
	if (strcmp(str, "111") == 0) {
		*a = 3;
		*b = 15;
		return 59;
	}
	if (strcmp(str, "112") == 0) {
		*a = 3;
		*b = 16;
		return 60;
	}
	if (strcmp(str, "110") == 0) {
		*a = 3;
		*b = 14;
		return 61;
	}
	if (strcmp(str, "20") == 0) {
		*a = 0;
		*b = 20;
		return 62;
	}
	if (strcmp(str, "7") == 0) {
		*a = 0;
		*b = 7;
		return 63;
	}
	if (strcmp(str, "P8_3") == 0) {
		*a = 1;
		*b = 6;
		return 64;
	}
	if (strcmp(str, "P8_4") == 0) {
		*a = 1;
		*b = 7;
		return 65;
	}
	if (strcmp(str, "P8_5") == 0) {
		*a = 1;
		*b = 2;
		return 66;
	}
	if (strcmp(str, "P8_6") == 0) {
		*a = 1;
		*b = 3;
		return 67;
	}
	if (strcmp(str, "P8_7") == 0) {
		*a = 2;
		*b = 2;
		return 68;
	}
	if (strcmp(str, "P8_8") == 0) {
		*a = 2;
		*b = 3;
		return 69;
	}
	if (strcmp(str, "P8_9") == 0) {
		*a = 2;
		*b = 5;
		return 70;
	}
	if (strcmp(str, "P8_10") == 0) {
		*a = 2;
		*b = 4;
		return 71;
	}
	if (strcmp(str, "P8_11") == 0) {
		*a = 1;
		*b = 13;
		return 72;
	}
	if (strcmp(str, "P8_12") == 0) {
		*a = 1;
		*b = 12;
		return 73;
	}
	if (strcmp(str, "P8_13") == 0) {
		*a = 0;
		*b = 23;
		return 74;
	}
	if (strcmp(str, "P8_14") == 0) {
		*a = 0;
		*b = 26;
		return 75;
	}
	if (strcmp(str, "P8_15") == 0) {
		*a = 1;
		*b = 15;
		return 76;
	}
	if (strcmp(str, "P8_16") == 0) {
		*a = 1;
		*b = 14;
		return 77;
	}
	if (strcmp(str, "P8_17") == 0) {
		*a = 0;
		*b = 27;
		return 78;
	}
	if (strcmp(str, "P8_18") == 0) {
		*a = 2;
		*b = 1;
		return 79;
	}
	if (strcmp(str, "P8_19") == 0) {
		*a = 0;
		*b = 22;
		return 80;
	}
	if (strcmp(str, "P8_20") == 0) {
		*a = 1;
		*b = 31;
		return 81;
	}
	if (strcmp(str, "P8_21") == 0) {
		*a = 1;
		*b = 30;
		return 82;
	}
	if (strcmp(str, "P8_22") == 0) {
		*a = 1;
		*b = 5;
		return 83;
	}
	if (strcmp(str, "P8_23") == 0) {
		*a = 1;
		*b = 4;
		return 84;
	}
	if (strcmp(str, "P8_24") == 0) {
		*a = 1;
		*b = 1;
		return 85;
	}
	if (strcmp(str, "P8_25") == 0) {
		*a = 1;
		*b = 0;
		return 86;
	}
	if (strcmp(str, "P8_26") == 0) {
		*a = 1;
		*b = 29;
		return 87;
	}
	if (strcmp(str, "P8_27") == 0) {
		*a = 2;
		*b = 22;
		return 88;
	}
	if (strcmp(str, "P8_28") == 0) {
		*a = 2;
		*b = 24;
		return 89;
	}
	if (strcmp(str, "P8_29") == 0) {
		*a = 2;
		*b = 23;
		return 90;
	}
	if (strcmp(str, "P8_30") == 0) {
		*a = 2;
		*b = 25;
		return 91;
	}
	if (strcmp(str, "P8_31") == 0) {
		*a = 0;
		*b = 10;
		return 92;
	}
	if (strcmp(str, "P8_32") == 0) {
		*a = 0;
		*b = 11;
		return 93;
	}
	if (strcmp(str, "P8_33") == 0) {
		*a = 0;
		*b = 9;
		return 94;
	}
	if (strcmp(str, "P8_34") == 0) {
		*a = 2;
		*b = 17;
		return 95;
	}
	if (strcmp(str, "P8_35") == 0) {
		*a = 0;
		*b = 8;
		return 96;
	}
	if (strcmp(str, "P8_36") == 0) {
		*a = 2;
		*b = 16;
		return 97;
	}
	if (strcmp(str, "P8_37") == 0) {
		*a = 2;
		*b = 14;
		return 98;
	}
	if (strcmp(str, "P8_38") == 0) {
		*a = 2;
		*b = 15;
		return 99;
	}
	if (strcmp(str, "P8_39") == 0) {
		*a = 2;
		*b = 12;
		return 100;
	}
	if (strcmp(str, "P8_40") == 0) {
		*a = 2;
		*b = 13;
		return 101;
	}
	if (strcmp(str, "P8_41") == 0) {
		*a = 2;
		*b = 10;
		return 102;
	}
	if (strcmp(str, "P8_42") == 0) {
		*a = 2;
		*b = 11;
		return 103;
	}
	if (strcmp(str, "P8_43") == 0) {
		*a = 2;
		*b = 8;
		return 104;
	}
	if (strcmp(str, "P8_44") == 0) {
		*a = 2;
		*b = 9;
		return 105;
	}
	if (strcmp(str, "P8_45") == 0) {
		*a = 2;
		*b = 6;
		return 106;
	}
	if (strcmp(str, "P8_46") == 0) {
		*a = 2;
		*b = 7;
		return 107;
	}
	if (strcmp(str, "TIMER4") == 0) {
		*a = 2;
		*b = 2;
		return 108;
	}
	if (strcmp(str, "TIMER7") == 0) {
		*a = 2;
		*b = 3;
		return 109;
	}
	if (strcmp(str, "TIMER5") == 0) {
		*a = 2;
		*b = 5;
		return 110;
	}
	if (strcmp(str, "TIMER6") == 0) {
		*a = 2;
		*b = 4;
		return 111;
	}
	if (strcmp(str, "EHRPWM2BK") == 0) {
		*a = 0;
		*b = 23;
		return 112;
	}
	if (strcmp(str, "EHRPWM2AK") == 0) {
		*a = 0;
		*b = 22;
		return 113;
	}
	if (strcmp(str, "UART5_CTSN") == 0) {
		*a = 0;
		*b = 10;
		return 114;
	}
	if (strcmp(str, "UART5_RTSN") == 0) {
		*a = 0;
		*b = 11;
		return 115;
	}
	if (strcmp(str, "UART4_RTSN") == 0) {
		*a = 0;
		*b = 9;
		return 116;
	}
	if (strcmp(str, "UART3_RTSN") == 0) {
		*a = 2;
		*b = 17;
		return 117;
	}
	if (strcmp(str, "UART4_CTSN") == 0) {
		*a = 0;
		*b = 8;
		return 118;
	}
	if (strcmp(str, "UART3_CTSN") == 0) {
		*a = 2;
		*b = 16;
		return 119;
	}
	if (strcmp(str, "UART5_TXDN") == 0) {
		*a = 2;
		*b = 14;
		return 120;
	}
	if (strcmp(str, "UART5_RXDN") == 0) {
		*a = 2;
		*b = 15;
		return 121;
	}
	if (strcmp(str, "38") == 0) {
		*a = 1;
		*b = 6;
		return 122;
	}
	if (strcmp(str, "39") == 0) {
		*a = 1;
		*b = 7;
		return 123;
	}
	if (strcmp(str, "34") == 0) {
		*a = 1;
		*b = 2;
		return 124;
	}
	if (strcmp(str, "35") == 0) {
		*a = 1;
		*b = 3;
		return 125;
	}
	if (strcmp(str, "66") == 0) {
		*a = 2;
		*b = 2;
		return 126;
	}
	if (strcmp(str, "67") == 0) {
		*a = 2;
		*b = 3;
		return 127;
	}
	if (strcmp(str, "69") == 0) {
		*a = 2;
		*b = 5;
		return 128;
	}
	if (strcmp(str, "68") == 0) {
		*a = 2;
		*b = 4;
		return 129;
	}
	if (strcmp(str, "45") == 0) {
		*a = 1;
		*b = 13;
		return 130;
	}
	if (strcmp(str, "44") == 0) {
		*a = 1;
		*b = 12;
		return 131;
	}
	if (strcmp(str, "23") == 0) {
		*a = 0;
		*b = 23;
		return 132;
	}
	if (strcmp(str, "26") == 0) {
		*a = 0;
		*b = 26;
		return 133;
	}
	if (strcmp(str, "47") == 0) {
		*a = 1;
		*b = 15;
		return 134;
	}
	if (strcmp(str, "46") == 0) {
		*a = 1;
		*b = 14;
		return 135;
	}
	if (strcmp(str, "27") == 0) {
		*a = 0;
		*b = 27;
		return 136;
	}
	if (strcmp(str, "65") == 0) {
		*a = 2;
		*b = 1;
		return 137;
	}
	if (strcmp(str, "22") == 0) {
		*a = 0;
		*b = 22;
		return 138;
	}
	if (strcmp(str, "63") == 0) {
		*a = 1;
		*b = 31;
		return 139;
	}
	if (strcmp(str, "62") == 0) {
		*a = 1;
		*b = 30;
		return 140;
	}
	if (strcmp(str, "37") == 0) {
		*a = 1;
		*b = 5;
		return 141;
	}
	if (strcmp(str, "36") == 0) {
		*a = 1;
		*b = 4;
		return 142;
	}
	if (strcmp(str, "33") == 0) {
		*a = 1;
		*b = 1;
		return 143;
	}
	if (strcmp(str, "32") == 0) {
		*a = 1;
		*b = 0;
		return 144;
	}
	if (strcmp(str, "61") == 0) {
		*a = 1;
		*b = 29;
		return 145;
	}
	if (strcmp(str, "86") == 0) {
		*a = 2;
		*b = 22;
		return 146;
	}
	if (strcmp(str, "88") == 0) {
		*a = 2;
		*b = 24;
		return 147;
	}
	if (strcmp(str, "87") == 0) {
		*a = 2;
		*b = 23;
		return 148;
	}
	if (strcmp(str, "89") == 0) {
		*a = 2;
		*b = 25;
		return 149;
	}
	if (strcmp(str, "10") == 0) {
		*a = 0;
		*b = 10;
		return 150;
	}
	if (strcmp(str, "11") == 0) {
		*a = 0;
		*b = 11;
		return 151;
	}
	if (strcmp(str, "9") == 0) {
		*a = 0;
		*b = 9;
		return 152;
	}
	if (strcmp(str, "81") == 0) {
		*a = 2;
		*b = 17;
		return 153;
	}
	if (strcmp(str, "8") == 0) {
		*a = 0;
		*b = 8;
		return 154;
	}
	if (strcmp(str, "80") == 0) {
		*a = 2;
		*b = 16;
		return 155;
	}
	if (strcmp(str, "78") == 0) {
		*a = 2;
		*b = 14;
		return 156;
	}
	if (strcmp(str, "79") == 0) {
		*a = 2;
		*b = 15;
		return 157;
	}
	if (strcmp(str, "76") == 0) {
		*a = 2;
		*b = 12;
		return 158;
	}
	if (strcmp(str, "77") == 0) {
		*a = 2;
		*b = 13;
		return 159;
	}
	if (strcmp(str, "74") == 0) {
		*a = 2;
		*b = 10;
		return 160;
	}
	if (strcmp(str, "75") == 0) {
		*a = 2;
		*b = 11;
		return 161;
	}
	if (strcmp(str, "72") == 0) {
		*a = 2;
		*b = 8;
		return 162;
	}
	if (strcmp(str, "73") == 0) {
		*a = 2;
		*b = 9;
		return 163;
	}
	if (strcmp(str, "70") == 0) {
		*a = 2;
		*b = 6;
		return 164;
	}
	if (strcmp(str, "71") == 0) {
		*a = 2;
		*b = 7;
		return 165;
	}
	fprintf(stderr, "%s: No value found for %s\n", __FUNCTION__, str);
	return -1;
}

#endif
