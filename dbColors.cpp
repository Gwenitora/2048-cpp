#include "colors.h"
#include "dbColors.h"

DbColors::DbColors()
{
	_emptyCell.setRGB(0xcdc1b4);

	_2.setRGB(0xeee4da);
	_4.setRGB(0xede0c8);
	_8.setRGB(0xf2b179);
	_16.setRGB(0xf59563);
	_32.setRGB(0xf67c60);
	_64.setRGB(0xf65e3b);
	_128.setRGB(0xedcf73);
	_256.setRGB(0xedcc62);
	_512.setRGB(0xedc850);
	_1024.setRGB(0xedc53f);
	_2048.setRGB(0xedc22d);
	_4096.setRGB(0xf0646e);
	_8192.setRGB(0xee4b5a);
	_16384.setRGB(0xe3413c);
	_32768.setRGB(0x72b2d6);
	_65536.setRGB(0x5f9ee2);
	_131072.setRGB(0x037bbe);

	_textBlack.setRGB(0x776e65);
	_textWhite.setRGB(0xf9f6f2);

	_border.setRGB(0xbbada0);
	_bg.setRGB(0xfaf8ef);
}

Color DbColors::getNumber(int val)
{
	switch (val)
	{
	case 2:
		return _defaultColor.mixin(_2, 1);
		break;
	case 4:
		return _defaultColor.mixin(_4, 1);
		break;
	case 8:
		return _defaultColor.mixin(_8, 1);
		break;
	case 16:
		return _defaultColor.mixin(_16, 1);
		break;
	case 32:
		return _defaultColor.mixin(_32, 1);
		break;
	case 64:
		return _defaultColor.mixin(_64, 1);
		break;
	case 128:
		return _defaultColor.mixin(_128, 1);
		break;
	case 256:
		return _defaultColor.mixin(_256, 1);
		break;
	case 512:
		return _defaultColor.mixin(_512, 1);
		break;
	case 1024:
		return _defaultColor.mixin(_1024, 1);
		break;
	case 2048:
		return _defaultColor.mixin(_2048, 1);
		break;
	case 4096:
		return _defaultColor.mixin(_4096, 1);
		break;
	case 8192:
		return _defaultColor.mixin(_8192, 1);
		break;
	case 16384:
		return _defaultColor.mixin(_16384, 1);
		break;
	case 32768:
		return _defaultColor.mixin(_32768, 1);
		break;
	case 65536:
		return _defaultColor.mixin(_65536, 1);
		break;
	case 131072:
		return _defaultColor.mixin(_131072, 1);
		break;
	default:
		return _defaultColor.mixin(_emptyCell, 1);
		break;
	}
}

Color DbColors::getText(int val)
{
	if (val == 2 || val == 4)
	{
		return getText(true);
	}
	return getText(false);
}

Color DbColors::getText(bool black)
{
	if (black)
	{
		return _defaultColor.mixin(_textBlack, 1);
	}
	return _defaultColor.mixin(_textWhite, 1);
}

Color DbColors::getBorder()
{
	return _defaultColor.mixin(_border, 1);
}

Color DbColors::getBackground()
{
	return _defaultColor.mixin(_bg, 1);
}
