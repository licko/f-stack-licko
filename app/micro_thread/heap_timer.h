
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
 * @file  heap_timer.h
 */

#ifndef _MICRO_THREAD_TIMER_H_
#define _MICRO_THREAD_TIMER_H_

#include <stdint.h>
#include "heap.h"

namespace NS_MICRO_THREAD
{

/**
 * @brief ��ʱ���������
 */
class CTimerNotify : public HeapEntry
{
public:

    /**
     * @brief ��ʱ֪ͨ����, ����ʵ���߼�
     */
    virtual void timer_notify() { return;};
    
    /**
     *  @brief ��Ԫ��ȡֵ����, ���ڷ���ֵ�Ƚ�, ���Ӻ���ʵ��, ����Ĭ������
     *  @return ��Ԫ��ӳ���ֵ
     */
    virtual unsigned long long HeapValue() {
        return (unsigned long long)_time_expired;
    }; 

    /**
     * @brief ���캯��
     */
    CTimerNotify() : _time_expired(0) {};

    /**
     * @brief ����������
     */
    virtual ~CTimerNotify(){};

    /**
     * @brief ���þ��Գ�ʱʱ��, ��λms
     * @param expired ���Գ�ʱʱ�� ms��λ
     */
    void set_expired_time(uint64_t expired) {
        _time_expired = expired;    
    };

    /**
     * @brief ��ȡ���Գ�ʱʱ��, ��λms
     * @return ���Գ�ʱʱ�� ms��λ
     */
    uint64_t get_expired_time() {
        return _time_expired;        
    };

private:

    uint64_t        _time_expired;     // ���Եĳ�ʱʱ��ms��λ
};


/**
 * @brief ��ʱ����������
 */
class CTimerMng
{
public:


    /**
     * @brief ���캯��
     * @param max_item ���ɹ���Ķ�ʱ��������Ŀ(ָ����Ŀ)
     */
    explicit CTimerMng(uint32_t max_item = 100000);    

    /**
     * @brief ��������
     */
    ~CTimerMng();

    /**
     * @brief ��ʱ�����ú���
     * @param timerable ��ʱ������
     * @param interval  ��ʱ�ļ�� ms��λ
     * @return �ɹ�����true, ����ʧ��
     */
    bool start_timer(CTimerNotify* timerable, uint32_t interval);    

    /**
     * @brief ��ʱ��ֹͣ�ӿں���
     * @param timerable ��ʱ������
     */
    void stop_timer(CTimerNotify* timerable);

    /**
     * @brief ��ʱ����ʱ��⺯��
     */
    void check_expired();

private:
    
    HeapList*           _heap;      // ��С��ָ��
};

}

#endif

