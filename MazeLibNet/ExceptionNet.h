#pragma once
using namespace System;
public ref class ExZeroHpNet : public Exception {
	String^ message;
public:
	ExZeroHpNet() : message("Null HP"){}
	ExZeroHpNet(String^ _message) : message(_message){}
	String^ what() {
		return message;
	}
};

public ref class ExWallHitNet : public Exception
{
	String^ message;
public:
	ExWallHitNet() : message("Oof!"){}
	String^ what(){
		return message;
	}
};
public ref class ExExitNet : public Exception
{
	String^ message;
public:
	ExExitNet() : message("Collect all coins.") {}
	String^ what() {
		return message;
	}
};
public ref class ExWinNet : public Exception
{
	String^ message;
public:
	ExWinNet() : message("You Win!!!"){}
	ExWinNet(String^ _message) : message(_message){}
	String^ what() {
		return message;
	}
};
