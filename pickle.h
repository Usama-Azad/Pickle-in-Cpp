/**                        -*- @c C/C++ headers -*-
*
*                        -*- @c #include"pickle.h" -*-
*
*                          -*- @version @c 1.0.1 -*-
**/

/**
 * @warning This Pickle @class can't pickle the object of those class which contains pointers in their data_members @c like vector, string etc.
 * 
 * @e Just_for_Educational_Purpose.
 * 
 * @author Usama Azad.
 * 
 * @a Just_Pickle_C++_Objects.
 * 
 * @file "pickle.h" for portable representations of C++ objects.
 * 
 * @functions:
 * {
 *      @c dump()
 *      @c load()
 *      @c dumps()
 *      @c loads()
 * }
 * 
 * @desc Created on 08-08-2020 07:00:00 pm.
 * 
 * @copyright All Right are Reserved.
 * 
**/


#ifndef __pickle_H__
#define __pickle_H__

#ifdef __cplusplus

#include "pickleException.h"
#include <fstream>

/**
 * @namespace @c usa : Pakage name for @class Pickle. 
**/
namespace usa
{

    /**
     * @class Pickle for portable representations of C++ objects.
     * 
     * @warning This Pickle @class can't pickle the object of those class which contains pointers in their data_members @c like vector, string etc.
     * 
     * @a Just_Pickle_C++_Objects.
     * 
     * @methods:
     * {
     *      @c dump()
     *      @c load()
     *      @c dumps()
     *      @c loads()
     * }
    **/
    class Pickle
    {

    public:
        /**
         * @brief @c dump() receive file name @c without_Extension as first parameter then create the file and pickle the object (given as second parameter) into this file.
         * @param filename:string receive file name without Extension then create the file and pickle the object into this file.
         * @param __obj:T receive @c non_empty_object of type T and pickle the object into file.
         * @return returns nothing.
        **/
        template<typename T>
        void dump(std::string filename, T &__obj)
        {
            if (!check_file_name(filename))
                throw file_name_error();

            filename = filename + std::string(".bin");

            std::ofstream fout(filename, std::ios::binary);

            if (!fout.is_open())
                throw file_open_error();

            fout.write((const char *)&__obj, sizeof(__obj));
            fout.close();
        }


    public:
        /**
         * @brief @c load() receive file name @c without_Extension as first parameter then read the file and retrieve the pickled object from the file and stores it into the object given as second parameter.
         * @param filename:string receive file name without Extension and then read the file and retrieve the pickled object from file.
         * @param __obj:T receive @c empty_Object of type T and then copy the pickled object which is retrieve from file.
         * @return returns nothing.
        **/
        template <typename T>
        void load(std::string filename, T &__obj)
        {
            if (!check_file_name(filename))
                throw file_name_error();

            filename = filename + std::string(".bin");

            std::ifstream fin(filename, std::ios::binary);

            if (!fin.is_open())
                throw file_open_error();

            fin.read((char *)&__obj, sizeof(__obj));
            fin.close();
        }


    public:
        /**
         * @brief @c dumps() receive file name @c without_Extension as first parameter then create the file and pickle the Array of objects (given as second parameter) into this file.
         * @param filename:string receive file name without Extension then create the file and pickle the Array of objects into this file.
         * @param __obj:T receive @c non_empty_Array_of_objects of type T and pickle the objects into file.
         * @return returns nothing.
        **/
        template<typename T,size_t n>
        void dumps(std::string filename, T (&__obj)[n])
        {
            if (!check_file_name(filename))
                throw file_name_error();

            filename = filename + std::string(".bin");

            std::ofstream fout(filename, std::ios::binary | std::ios::app);

            if (!fout.is_open())
                throw file_open_error();

            for (int i = 0; i < n; i++)
                fout.write((const char *)&__obj[i], sizeof(__obj[i]));

            fout.close();
        }


    public:
        /**
         * @brief @c loads() receive file name @c without_Extension as first parameter then read the file and retrieve the pickled objects Array from the file and stores it into the Array of objects given as second parameter.
         * @param filename:string receive file name without Extension and then read the file and retrieve the pickled objects Array from file.
         * @param __obj:T receive @c empty_Array_of_Objects of type T and then copy the pickled objects Array which is retrieve from file.
         * @return returns nothing.
        **/
        template <typename T, size_t n>
        void loads(std::string filename, T (&__obj)[n])
        {
            if (!check_file_name(filename))
                throw file_name_error();

            filename = filename + std::string(".bin");

            std::ifstream fin(filename, std::ios::binary);

            if (!fin.is_open())
                throw file_open_error();

            for (int i = 0; i < n; i++)
                fin.read((char *)&__obj[i], sizeof(__obj[i]));

            fin.close();
        }
    };

} // namespace usa

#endif
#endif