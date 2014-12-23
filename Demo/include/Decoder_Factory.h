#ifndef HUNDSUN_PUBLIC_DECODER_FACTORY_H
#define HUNDSUN_PUBLIC_DECODER_FACTORY_H

#include "Basic_Types.h"
#include "Fast_Decoder.h"

/***
 * @class IDecoder_Factory
 * @func ���ݽ���������
 */
class IDecoder_Factory
{
public:
  

  /***
   *@method GetFastDecoder
   *@func   ��ȡFAST������
   *@param
   *    ft:  FAST������������
   *@return
   *        0:   failed.
   *  Nonzero:   succ. Call Release() after used.
   */
  virtual IFast_Decoder* FUNCTION_CALL_MODE GetFastDecoder (FAST_TYPE ft) = 0 ;

  /***
   *@method GetLastError
   *@func   ��ȡ���Ĵ�����Ϣ
   *@return
   *     0: no error.
   * other: error info. 
   */
  virtual const char* FUNCTION_CALL_MODE GetLastError () = 0 ;

  /***
   *@method GetInstance
   *@func   ��ȡDecoder����ʵ��
   */
  static IDecoder_Factory* FUNCTION_CALL_MODE GetInstance () ;
} ;

#ifdef __cplusplus
extern "C" {
#endif

	IDecoder_Factory * FUNCTION_CALL_MODE GetDecoderFactoryInstance();

#ifdef __cplusplus
}
#endif

#endif