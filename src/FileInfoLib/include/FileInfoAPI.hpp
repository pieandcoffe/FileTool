//
// Created by Kyrylo Pylinskyi on 16/08/2025.
//

#ifndef FILETOOL_FILE_INFO_API_HPP
#define FILETOOL_FILE_INFO_API_HPP

#if defined(_WIN32) || defined(_WIN64)
  #ifdef _EXPORTING
    #define FILE_INFO_API __declspec(dllexport)
  #elif defined(_IMPORTING)
    #define FILE_INFO_API __declspec(dllimport)
  #else
    #define FILE_INFO_API
  #endif
#else
  #define FILE_INFO_API __attribute__((visibility("default")))
#endif


#endif //FILETOOL_FILE_INFO_API_HPP