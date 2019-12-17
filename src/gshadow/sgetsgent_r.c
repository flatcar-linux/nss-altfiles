/* Copyright (C) 2009-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#include <ctype.h>
#include <errno.h>
#include <gshadow.h>
#include <stdio.h>
#include <string.h>

/* Define a line parsing function using the common code
   used in the nss_files module.  */

#define STRUCTURE	sgrp
#define ENTNAME		sgent
struct sgent_data {};


#define TRAILING_LIST_MEMBER		sg_mem
#define TRAILING_LIST_SEPARATOR_P(c)	((c) == ',')
#include "../nss_altfiles/files-parse.c"
LINE_PARSER
(,
 STRING_FIELD (result->sg_namp, ISCOLON, 0);
 if (line[0] == '\0'
     && (result->sg_namp[0] == '+' || result->sg_namp[0] == '-'))
   {
     result->sg_passwd = NULL;
     result->sg_adm = NULL;
     result->sg_mem = NULL;
   }
 else
   {
     STRING_FIELD (result->sg_passwd, ISCOLON, 0);
     STRING_LIST (result->sg_adm, ':');
   }
 )
