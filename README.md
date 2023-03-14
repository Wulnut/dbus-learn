<!--
 * @Author: Wulnut carepdime@gmail.com
 * @Date: 2023-03-14 11:19:45
 * @LastEditors: Wulnut carepdime@gmail.com
 * @LastEditTime: 2023-03-14 11:41:24
 * @FilePath: /dbus-learn/README.md
 * @Description:
-->
# dbus-learn
dbus study demo


## test command

Add object path command:

```shell
dbus-send --session --print-reply --dest=com.upointech.dbus /com/upointech/dbus/Test com.upointech.dbus.ObjectManager.AddObject
```

Delete object path command:

```shell
dbus-send --session --print-reply --dest=com.upointech.dbus /com/upointech/dbus/Test com.upointech.dbus.ObjectManager.DeleteObject objpath:/com/upointech/dbus/Test/1
```

Get all object path command

```shell
dbus-send --session --print-reply --dest=com.upointech.dbus /com/upointech/dbus/Test com.upointech.dbus.ObjectManager.GetManagedObjects
```

