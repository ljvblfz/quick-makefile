#include "hsl_os.h"
#include "hsl_types.h"
#include "hsl_oss.h"

/************************************************************************************
 * Function: oss_printf  - Service routine to log a message                         *
 * Parameters:                                                                      *
 *   IN  format - message format.                                                   *
 *   arguments                                                                      *
 * Return value:                                                                    *
 *   void                                                                           *
 ************************************************************************************/
void 
oss_printf(const char* format, ...)
{
   char buf[OSS_LOG_BUFFER_SIZE];
   va_list args;

   va_start(args, format);
   vsprintf(buf, format, args);
   va_end(args);
   printk ("%s", buf);
}
