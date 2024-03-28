#ifndef INC_APP_H_
#define INC_APP_H_

#include "cmsis_os.h"

#ifdef __cplusplus
extern "C" {
#endif

  void app_loop(void);
  void app_c(void);
  void app_init(void);
  
#ifdef __cplusplus
}
#endif
 
void app(void);
 
#endif /* INC_APP_H_ */
