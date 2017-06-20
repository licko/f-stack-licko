
/**
 * Tencent is pleased to support the open source community by making MSEC available.
 *
 * Copyright (C) 2016 THL A29 Limited, a Tencent company. All rights reserved.
 *
 * Licensed under the GNU General Public License, Version 2.0 (the "License"); 
 * you may not use this file except in compliance with the License. You may 
 * obtain a copy of the License at
 *
 *     https://opensource.org/licenses/GPL-2.0
 *
 * Unless required by applicable law or agreed to in writing, software distributed under the 
 * License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific language governing permissions
 * and limitations under the License.
 */


/**
 *  @file mt_concurrent.h
 *  @info ��չ״̬�̵߳Ĵ���ģ��
 *  @time 20130515
 **/

#ifndef __MT_CONCURRENT_H__
#define __MT_CONCURRENT_H__

#include <netinet/in.h>
#include <vector>

namespace NS_MICRO_THREAD {

using std::vector;

class IMtAction;
typedef vector<IMtAction*>  IMtActList;

/******************************************************************************/
/*  ΢�߳��û��ӿڶ���: ΢�߳�Action��·����ģ�ͽӿڶ���                      */
/******************************************************************************/

/**
 * @brief ��·IO�������մ���ӿ�, ��װACTON�ӿ�ģ��, �ڲ�����msg
 * @param req_list -action list ʵ�ַ�װ�����ӿ�
 * @param timeout -��ʱʱ��, ��λms
 * @return  0 �ɹ�, -1 ��socketʧ��, -2 ��������ʧ��, -100 ����Ӧ�𲿷�ʧ��, �ɴ�ӡerrno
 */
int mt_msg_sendrcv(IMtActList& req_list, int timeout);

/******************************************************************************/
/*  �ڲ�ʵ�ֶ��岿��                                                          */
/******************************************************************************/

/**
 * @brief ��·IO�Ĵ����Ż�, �첽���ȵȴ�����
 * @param req_list - �����б�
 * @param how - EPOLLIN  EPOLLOUT
 * @param timeout - ��ʱʱ�� ���뵥λ
 * @return 0 �ɹ�, <0ʧ�� -3 ����ʱ
 */
int mt_multi_netfd_poll(IMtActList& req_list, int how, int timeout);

/**
 * @brief Ϊÿ��ITEM���������ĵ�socket
 * @param req_list - �����б�
 * @return 0 �ɹ�, <0ʧ��
 */
int mt_multi_newsock(IMtActList& req_list);

/**
 * @brief ��·IO�Ĵ���, ������
 * @param req_list - �����б�
 * @param timeout - ��ʱʱ�� ���뵥λ
 * @return 0 �ɹ�, <0ʧ��
 */
int mt_multi_open(IMtActList& req_list, int timeout);

/**
 * @brief ��·IO�Ĵ���, ��������
 * @param req_list - �����б�
 * @param timeout - ��ʱʱ�� ���뵥λ
 * @return 0 �ɹ�, <0ʧ��
 */
int mt_multi_sendto(IMtActList& req_list, int timeout);

/**
 * @brief ��·IO�������մ���
 */
int mt_multi_recvfrom(IMtActList& req_list, int timeout);

/**
 * @brief ��·IO�������մ���
 */
int mt_multi_sendrcv_ex(IMtActList& req_list, int timeout);

}



#endif


