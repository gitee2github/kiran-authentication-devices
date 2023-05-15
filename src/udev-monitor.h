/**
 * Copyright (c) 2020 ~ 2021 KylinSec Co., Ltd.
 * kiran-authentication-devices is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PSL v2 for more details.
 *
 * Author:     luoqing <luoqing@kylinsec.com.cn>
 */
#pragma once

#include <libudev.h>
#include <QObject>
#include <QSharedPointer>
#include <QSocketNotifier>
#include "auth-enum.h"

namespace Kiran
{
class UdevMonitor : public QObject
{
    Q_OBJECT
public:
    explicit UdevMonitor(QObject *parent = nullptr);
    ~UdevMonitor();

private Q_SLOTS:
    void onSocketNotifierRead(int socket);

Q_SIGNALS:
    void deviceAdded(DeviceInfo deviceInfo);
    void deviceDeleted();

private:
    void init();

private:
    udev *m_udev;
    udev_monitor *m_monitor;
    QSharedPointer<QSocketNotifier> m_socketNotifierRead;
    int m_monitorFD;
};
}  // namespace Kiran
