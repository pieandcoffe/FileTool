//
// Created by Kyrylo Pylinskyi on 16/08/2025.
//

#ifndef FILETOOL_FILEOPSAPI_HPP
#define FILETOOL_FILEOPSAPI_HPP

#if defined(_WIN32) || defined(_WIN64)
  #ifdef _EXPORTING
    #define FILE_OPS_API __declspec(dllexport)
  #elif defined(_IMPORTING)
    #define FILE_OPS_API __declspec(dllimport)
  #else
    #define FILE_OPS_API
  #endif
#else
  #define FILE_OPS_API __attribute__((visibility("default")))
#endif


#endif //FILETOOL_FILEOPSAPI_HPP