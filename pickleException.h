///                          -*- @c C/C++ Library -*-

///                        -*- @c #include"pickle.h" -*-

/**
 * Standerd @c Exception file for @c pickle Module.
**/

/** 
 * @author @c "Usama_Azad"
 * 
 * All the Rights are reserved @c 2k20 @c 2k21.
 * 
 * This file is not a @c C/C++ standard @c Header.
**/

#ifndef __pickle_Exception__
#define __pickle_Exception__

#ifdef __cplusplus

#include <string>
#include <stdexcept>


class file_name_error : public std::runtime_error 
{
public:
    file_name_error() 
    : runtime_error("File name is Invalid: Please enter only file name without Extension...") {}
};


class file_open_error : public std::runtime_error 
{
public:
    file_open_error() 
    : runtime_error("File does not open: Please check file name or file present in your current working directory and try again...") {}
};


bool check_file_name(std::string filename)
{
    for (auto c : filename)
        if (c == '.' || c == '*')
            return false;
    return true;
}

#endif
#endif