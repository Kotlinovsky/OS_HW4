# Программа на 4-5 баллов
Программа реализована с помощью стандартных сокетов Linux API. При подключении к серверу клиент отправляет свой ID и пол. 
Сервер на основе полученных данных ищет свободную комнату и если все ок, то сообщает клиенту о том, что комната была забронирована, иначе же сервер возвращает сообщение о том,
что комнату забронировать не удалось. Аренда комнаты начинается с момента, когда удалось ее забронировать до момента получения сообщения от клиента об окончании аренды.

## Пример работы программы
Сначала запускаем сервер на 25593 порту.
Затем подключаем к нему соответствующие клиенты - 40 женщин и 1 мужчину.
Как видим, мы смогли заселить 40 женщин, но не смогли заселить 1 мужчину, т.к. все номера были заняты.
Следственно программа работает правильно.

```
> /home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Hotel 25593
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 1 WOMAN 10 127.0.0.1 25593

> /home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 1 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 2 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 3 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 4 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 5 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 6 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 7 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 8 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 9 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 10 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 21 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 22 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 23 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 24 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 25 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 26 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 27 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 28 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 29 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 210 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 321 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 322 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 323 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 324 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 325 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 326 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 327 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 328 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 329 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 3210 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 421 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 422 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 423 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 424 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 425 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 426 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 427 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 428 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 429 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 4210 WOMAN 10 127.0.0.1 25593 &
/home/kotlinovsky/Projects/OS/IDZ4/cmake-build-debug/IDZ4_Grade4-5_Client 54210 MAN 10 127.0.0.1 25593

[CLIENT] Client_id = 5; client = 0; rent_time = 10
[CLIENT] Client_id = 2; client = 0; rent_time = 10
[CLIENT] Client_id = 3; client = 0; rent_time = 10
[CLIENT] Client_id = 6; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Notifying hotel ...
[CLIENT] Notifying hotel ...
[CLIENT] Notifying hotel ...
[CLIENT] Client_id = 7; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Waiting hotel response ...
[CLIENT] Waiting hotel response ...
[CLIENT] Waiting hotel response ...
[CLIENT] Waiting hotel response ...
[CLIENT] Client_id = 1; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Waiting hotel response ...
[CLIENT] Waiting hotel response ...
[CLIENT] Client_id = 4; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Waiting hotel response ...
[CLIENT] Client_id = 8; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Waiting hotel response ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Client_id = 9; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Waiting hotel response ...
[CLIENT] Client_id = 27; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Waiting hotel response ...
[CLIENT] Client_id = 22; client = 0; rent_time = 10
[CLIENT] Client_id = 26; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Notifying hotel ...
[CLIENT] Waiting hotel response ...
[CLIENT] Waiting hotel response ...
[CLIENT] Client_id = 10; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Client_id = 29; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Waiting hotel response ...
[CLIENT] Client_id = 24; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Waiting hotel response ...
[CLIENT] Waiting hotel response ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Client_id = 325; client = 0; rent_time = 10
[CLIENT] Client_id = 324; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Notifying hotel ...
[CLIENT] Client_id = 210; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Waiting hotel response ...
[CLIENT] Waiting hotel response ...
[CLIENT] Waiting hotel response ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Client_id = 422; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Waiting hotel response ...
[CLIENT] Client_id = 323; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Waiting hotel response ...
[CLIENT] Client_id = 423; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Waiting hotel response ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Client_id = 421; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Waiting hotel response ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Client_id = 28; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Waiting hotel response ...
[CLIENT] Client_id = 326; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Waiting hotel response ...
[CLIENT] Client_id = 21; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Waiting hotel response ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Client_id = 3210; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Waiting hotel response ...
[CLIENT] Client_id = 25; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Waiting hotel response ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Client_id = 321; client = 0; rent_time = 10
[CLIENT] Client_id = 329; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Notifying hotel ...
[CLIENT] Waiting hotel response ...
[CLIENT] Waiting hotel response ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Client_id = 23; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Client_id = 429; client = 0; rent_time = 10
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Waiting hotel response ...
[CLIENT] Notifying hotel ...
[CLIENT] Waiting hotel response ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Client_id = 427; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Client_id = 322; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Waiting hotel response ...
[CLIENT] Waiting hotel response ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Client_id = 327; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Waiting hotel response ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Client_id = 54210; client = 1; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Waiting hotel response ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Client_id = 428; client = 0; rent_time = 10
[CLIENT] Client_id = 424; client = 0; rent_time = 10
[CLIENT] Client_id = 426; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Notifying hotel ...
[CLIENT] Notifying hotel ...
[CLIENT] Waiting hotel response ...
[CLIENT] Waiting hotel response ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Waiting hotel response ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Client_id = 328; client = 0; rent_time = 10
[CLIENT] Client_id = 425; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Notifying hotel ...
[CLIENT] Waiting hotel response ...
[CLIENT] Waiting hotel response ...
[CLIENT] Successfully rent! Waiting 10seconds ...
[CLIENT] Out of service!
[CLIENT] Client_id = 4210; client = 0; rent_time = 10
[CLIENT] Notifying hotel ...
[CLIENT] Waiting hotel response ...
[CLIENT] Out of service!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
[CLIENT] Rent done!
```