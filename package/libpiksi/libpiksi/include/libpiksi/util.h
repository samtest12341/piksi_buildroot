/*
 * Copyright (C) 2017 Swift Navigation Inc.
 * Contact: Jacob McNamee <jacob@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

/**
 * @file    util.h
 * @brief   Utilities API.
 *
 * @defgroup    util Util
 * @addtogroup  util
 * @{
 */

#ifndef LIBPIKSI_UTIL_H
#define LIBPIKSI_UTIL_H

#include <libpiksi/common.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Get the SBP sender ID for the system.
 * @details Returns the board-specific SBP sender ID.
 *
 * @return                  The SBP sender ID.
 */
u16 sbp_sender_id_get(void);

/**
 * @brief   Get system uptime
 * @return  Uptime in milliseconds
 */
u64 system_uptime_ms_get(void);

/**
 * @brief   Get the Device UUID for the system.
 * @details Returns the board-specific UUID.
 *
 * @return                  The operation result.
 * @retval 0                The value was returned successfully.
 * @retval -1               An error occurred.
 */
int device_uuid_get(char *str, size_t str_size);

/**
 * @brief   Determine if the current system is Duro
 * @details Returns the true or false
 *
 * @return  True if the current system is a Duro
 */
bool device_is_duro(void);

void reap_children(bool debug);

void setup_sigchild_handler(void (*handler)(int));

#define SWFT_MAX(a,b) \
  ({ typeof (a) _a = (a); \
  typeof (b) _b = (b); \
  _a > _b ? _a : _b; })

#define SWFT_MIN(a,b) \
  ({ typeof (a) _a = (a); \
  typeof (b) _b = (b); \
  _a < _b ? _a : _b; })

#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

#define lambda(TheReturnType, ...)              \
  __extension__                                 \
  ({                                            \
    TheReturnType __fn__ __VA_ARGS__            \
      __fn__;                                   \
  })

#define UNSTAGE_CLEANUP(TheReturn, TheType)                         \
  ({ TheType __unstage = TheReturn; TheReturn = NULL; __unstage; })

#define ARRAY_OF_FIXED_BLOCKS(TheType, TheSize) \
  TheType (*__unstage)[TheSize]

#define UNSTAGE_CLEANUP_X(TheReturn, TypeNameDecl)              \
  ({ TypeNameDecl = TheReturn; TheReturn = NULL; __unstage; })

#define STAGE_CLEANUP(TheVar, CleanUpExpr)                \
  void clean_up_ ## TheVar (int* _X_ ## TheVar) {         \
    (void) _X_ ## TheVar;                                 \
    CleanUpExpr;                                          \
  };                                                      \
  int _X_clean_up_ ## TheVar                              \
  __attribute__((__cleanup__(clean_up_ ## TheVar))) = 0;  \
  (void) _X_clean_up_ ## TheVar;                          \

#ifdef __cplusplus
}
#endif

#endif /* LIBPIKSI_UTIL_H */

/** @} */
