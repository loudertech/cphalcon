
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/debug.h"
#include "kernel/assert.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/memory.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

/**
 * Phalcon_View_Engine_Mustache
 *
 * Adapter to use Mustache library as templating engine
 */

/**
 * Phalcon_View_Engine_Mustache constructor
 *
 * @param Phalcon_View $view
 * @param array $options
 */
PHP_METHOD(Phalcon_View_Engine_Mustache, __construct){

	zval *view = NULL, *options = NULL, *mustache = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	int eval_int;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &view, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "Mustache", 1);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "class_exists", c0, 0x012);
	if (!zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_view_exception_ce);
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, "Mustache class must be loaded first", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c1, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	eval_int = phalcon_array_isset_string(options, "mustache", strlen("mustache")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, options, "mustache", strlen("mustache"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(mustache, r1);
	} else {
		ce0 = zend_fetch_class("Mustache", strlen("Mustache"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, ce0);
		PHALCON_CALL_METHOD_NORETURN(i1, "__construct", PHALCON_CHECK);
		PHALCON_CPY_WRT(mustache, i1);
	}
	
	phalcon_update_property_zval(this_ptr, "_mustache", strlen("_mustache"), mustache TSRMLS_CC);
	PHALCON_CALL_PARENT_PARAMS_2_NORETURN(this_ptr, "Phalcon_View_Engine_Mustache", "__construct", view, options);
	
	PHALCON_MM_RESTORE();
}

/**
 * Renders a view using the template engine
 *
 * @param string $path
 * @param array $params
 */
PHP_METHOD(Phalcon_View_Engine_Mustache, render){

	zval *path = NULL, *params = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &path, &params) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, "_params", strlen("_params"), params TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_view", sizeof("_view")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_mustache", sizeof("_mustache")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "file_get_contents", path, 0x01A);
	PHALCON_CALL_METHOD_PARAMS_2(r0, t1, "render", r1, this_ptr, PHALCON_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(t0, "setcontent", r0, PHALCON_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_View_Engine_Mustache, __isset){

	zval *property = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &property) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, property);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	
	PHALCON_RETURN_NCTOR(r0);
}

PHP_METHOD(Phalcon_View_Engine_Mustache, __get){

	zval *property = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &property) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, property);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_params", sizeof("_params")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, t1, property, PHALCON_NOISY TSRMLS_CC);
		
		PHALCON_RETURN_CHECK_CTOR(r0);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

PHP_METHOD(Phalcon_View_Engine_Mustache, __call){

	zval *method = NULL, *arguments = NULL;
	zval *a0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &method, &arguments) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_mustache", sizeof("_mustache")-1, PHALCON_NOISY TSRMLS_CC);
	phalcon_array_append(&a0, t0, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	phalcon_array_append(&a0, method, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_2_NORETURN("call_user_func_array", a0, arguments, 0x013);
	
	PHALCON_MM_RESTORE();
}

