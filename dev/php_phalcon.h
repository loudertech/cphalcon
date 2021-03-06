
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#ifndef PHP_PHALCON_H
#define PHP_PHALCON_H 1

#define PHP_PHALCON_VERSION "0.4.0"
#define PHP_PHALCON_EXTNAME "phalcon"

#define PHALCON_MAX_MEMORY_STACK 64
#define PHALCON_FCALL_MAX_CACHE 96

typedef struct _phalcon_memory_entry {
	int pointer;
	zval **addresses[PHALCON_MAX_MEMORY_STACK];
	struct _phalcon_memory_entry *prev;
	struct _phalcon_memory_entry *next;
} phalcon_memory_entry;

ZEND_BEGIN_MODULE_GLOBALS(phalcon)
	int phalcon_memory_stack;
	phalcon_memory_entry *start_memory;
	phalcon_memory_entry *active_memory;
	zend_fcall_info_cache *phalcon_fcall_cache[PHALCON_FCALL_MAX_CACHE];
#ifndef PHALCON_RELEASE
	int phalcon_stack_stats;
	int phalcon_fcall_stats;
#endif
ZEND_END_MODULE_GLOBALS(phalcon)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(phalcon)

#ifdef ZTS
	#define PHALCON_GLOBAL(v) TSRMG(phalcon_globals_id, zend_phalcon_globals *, v)
#else
	#define PHALCON_GLOBAL(v) (phalcon_globals.v)
#endif

extern zend_module_entry phalcon_module_entry;
#define phpext_phalcon_ptr &phalcon_module_entry

#ifdef PHP_WIN32
#include "stdafx.h"
#endif

#endif

#if PHP_VERSION_ID >= 50400
	#define PHALCON_INIT_FUNCS(class_functions) static const zend_function_entry class_functions[] =
#else
	#define PHALCON_INIT_FUNCS(class_functions) static const function_entry class_functions[] =
#endif

#ifndef PHP_FE_END
	#define PHP_FE_END { NULL, NULL, NULL, 0, 0 }
#endif
