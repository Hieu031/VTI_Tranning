/*
 * BasicTypes.h
 *
 *  Created on: May 9, 2025
 *      Author: hieu.nguyentri
 */

#ifndef INC_BASICTYPES_H_
#define INC_BASICTYPES_H_

#include <stdint.h>
/* define stdint.h as types over PlatformTypes.h */

#define __I				volatile
#define __IO			volatile
#define __O				volatile

typedef enum{
	FALSE = 0,
	TRUE = 1
} boolean;

#endif /* INC_BASICTYPES_H_ */
