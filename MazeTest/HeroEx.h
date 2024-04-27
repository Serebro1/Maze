#pragma once
#include <iostream>
using namespace std;
class HpEx : public exception
{
	string message;
public:
	HpEx(const string& _message) : message(_message) {}
	const char* what() const noexcept override
	{
		return message.c_str();
	}
};

class ExitEx : public exception
{
	string message;
public:
	ExitEx(const string& _message) : message(_message) {}
	const char* what() const noexcept override
	{
		return message.c_str();
	}
};

class WallEx : public exception
{
	string message;
public:
	WallEx(const string& _message) : message(_message) {}
	const char* what() const noexcept override
	{
		return message.c_str();
	}
};