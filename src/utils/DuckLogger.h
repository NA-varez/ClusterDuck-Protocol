#ifndef DUCKLOGGER_H
#define DUCKLOGGER_H
#include "tinyformat.h"
#include <cstdio>

#ifdef CDP_DEBUG
#define CDP_LOG_ERROR
#define CDP_LOG_INFO
#define CDP_LOG_DEBUG
#define CDP_LOG_WARN
#endif

#ifdef CDP_INFO
#define CDP_LOG_ERROR
#define CDP_LOG_INFO
#define CDP_LOG_WARN
#endif

#ifdef CDP_WARN
#define CDP_LOG_ERROR
#define CDP_LOG_WARN
#endif

#ifdef CDP_ERROR
#define CDP_LOG_ERROR
#endif

#ifndef __FILENAME__
#define __FILENAME__                                                           \
  (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#endif

#ifdef CDP_LOG_ERROR
#define logerr(format, ...)                                                    \
  do {                                                                         \
    ::printf("[E][** %s : %d] " format, __FILENAME__, __LINE__, ##__VA_ARGS__); \
  } while (0)
#define logerr_ln(format, ...)                                                 \
  do {                                                                         \
    ::printf("[E][** %s : %d] " format "\n", __FILENAME__, __LINE__, ##__VA_ARGS__); \
  } while (0)
#else
#define logerr(format, ...)                                     \
  {}
#define logerr_ln(format, ...)                                  \
  {}
#endif // CDP_LOG_ERROR


#ifdef CDP_LOG_WARN
#define logwarn(format, ...)                                                   \
  do {                                                                         \
    ::printf("[W][%s : %d] " format, __FILENAME__, __LINE__, ##__VA_ARGS__);   \
  } while (0)
#define logwarn_ln(format, ...)                                                \
  do {                                                                         \
    ::printf("[W][%s : %d] " format "\n", __FILENAME__, __LINE__, ##__VA_ARGS__); \
  } while (0)
#else
#define logwarn(format, ...)                                    \
  {}
#define logwarn_ln(format, ...)                                 \
  {}
#endif // CDP_LOG_WARN

#if defined(CDP_LOG_INFO)
#define loginfo(format, ...)                                                   \
  do {                                                                         \
    ::printf("[I][%s] " format, __FILENAME__, ##__VA_ARGS__);                  \
  } while (0)
#define loginfo_ln(format, ...)                                                \
  do {                                                                         \
    ::printf("[I][%s] " format "\n", __FILENAME__, ##__VA_ARGS__);             \
  } while (0)
#else
#define loginfo(format, ...)                                    \
  {}
#define loginfo_ln(format, ...)                                 \
  {}
#endif // CDP_LOG_INFO

#ifdef CDP_LOG_DEBUG
#define logdbg(format, ...)                                                    \
  do {                                                                         \
    ::printf("[D][** %s : %d] " format, __FILENAME__, __LINE__, ##__VA_ARGS__); \
  } while (0)
#define logdbg_ln(format, ...)                                                 \
  do {                                                                         \
    ::printf("[D][** %s : %d] " format "\n", __FILENAME__, __LINE__, ##__VA_ARGS__); \
  } while (0)
#else
#define logdbg(format, ...)                                     \
  {}
#define logdbg_ln(format, ...)                                  \
  {}
#endif
#endif