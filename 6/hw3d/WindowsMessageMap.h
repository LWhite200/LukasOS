#pragma once
#include <unordered_map>
#include <Windows.h>
#include <string>                // Include for std::string (repeated, redundant)

class WindowsMessageMap
{
public:
	WindowsMessageMap();
	std::string operator()( DWORD msg,LPARAM lp,WPARAM wp ) const;
private:
	std::unordered_map<DWORD,std::string> map;
};