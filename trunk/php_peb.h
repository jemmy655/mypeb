/*
 	Copyright (c) 2005-2010, York Liu <sadly@phpx.com>.
 	All rights reserved.
 	
 	Redistribution and use in source and binary forms, with or without
 	modification, are permitted provided that the following conditions are
 	met:
 	
 	    * Redistributions of source code must retain the above copyright
 	      notice, this list of conditions and the following disclaimer.
 	    * Redistributions in binary form must reproduce the above
 	      copyright notice, this list of conditions and the following
 	      disclaimer in the documentation and/or other materials provided
 	      with the distribution.
 	    * Neither the name Message Systems, Inc. nor the names
 	      of its contributors may be used to endorse or promote products
 	      derived from this software without specific prior written
 	      permission.
 	
 	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 	"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 	LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 	A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 	OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 	SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 	LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 	DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 	THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 	OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/* $Id: header,v 1.16.2.1.2.1 2007/01/01 19:32:09 iliaa Exp $ */

#ifndef PHP_PEB_H
#define PHP_PEB_H

extern zend_module_entry peb_module_entry;
#define phpext_peb_ptr &peb_module_entry

#ifdef PHP_WIN32
#define PHP_PEB_API __declspec(dllexport)
#else
#define PHP_PEB_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

#include "ei.h"
#include "erl_interface.h"

PHP_MINIT_FUNCTION(peb);
PHP_MSHUTDOWN_FUNCTION(peb);
PHP_RINIT_FUNCTION(peb);
PHP_RSHUTDOWN_FUNCTION(peb);
PHP_MINFO_FUNCTION(peb);

PHP_FUNCTION(peb_connect);
PHP_FUNCTION(peb_pconnect);
PHP_FUNCTION(peb_close);
PHP_FUNCTION(peb_send_byname);
PHP_FUNCTION(peb_send_bypid);
PHP_FUNCTION(peb_receive);
PHP_FUNCTION(peb_encode);
PHP_FUNCTION(peb_decode);
PHP_FUNCTION(peb_error);
PHP_FUNCTION(peb_errorno);

PHP_FUNCTION(peb_linkinfo);

PHP_FUNCTION(peb_status);


ZEND_BEGIN_MODULE_GLOBALS(peb)
	long global_value;

	long default_link;
	long num_link,num_persistent;
	long max_link,max_persistent;

	long errorno;
	char *error;

	long instanceid;
ZEND_END_MODULE_GLOBALS(peb)

/* In every utility function you add that needs to use variables
   in php_peb_globals, call TSRMLS_FETCH(); after declaring other
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as PEB_G(variable).  You are
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define PEB_G(v) TSRMG(peb_globals_id, zend_peb_globals *, v)
#else
#define PEB_G(v) (peb_globals.v)
#endif

#endif	/* PHP_PEB_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
