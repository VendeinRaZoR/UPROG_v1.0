**Универсальный программатор UPROG версии 1.0**

**Описание**

Предназначен для прошивки микросхем памяти через различные наиболее простые и распространенные интерфейсы, такие как LPT и COM(USB-UART).

Имеется возможность добавлять свои типы микросхем пользователем, посредством создания собственных библиотек для работы с конкретными семействами микросхем памяти определенного производителя. В меню программатора новые микросхемы добавляются посредством создания их описания в виде JSON файлов в папке json.

Имеется возможность добавлять свои форматы файлов прошивок, посредством модификации модулей в Python скриптах в папке python.

Библиотеки интерфейсов и протоколов не должны изменяться пользователем, а поставляются и обновляются как есть. В исключительных случаях возможно добавление новой библиотеки протокола пользователем

**Особенности программатора**  **UPROG**  **версии 1.0:**

- **Возможность создания пользовательских библиотек** - для работы с микросхемами памяти, но, исключительно, с перекомпиляцией всего проекта;
- **Работа только с**  **LPT**  **портом** – другие интерфейсы пока не поддерживаются;
- **Добавление новых микросхем в меню посредством**  **JSON**  **файлов –** добавление пользовательских микросхем, производителей памяти и ссылок на информацию о них в меню программатора посредством добавления и редактирования JSON файлов;
- **Добавление новых форматов файлов прошивок –** добавление пользовательских форматов прошивок (открытие и сохранение) путем дополнения логики модулей _fwSave_ и _fwLoad_ с указанием нового формата в переменной _fwFormat_ в Python скриптах;
- **Наглядный процесс прошивки микросхемы –** пословная визуализация (побайтная) процесса прошивки той или иной микросхемы в HEX таблице её адресного пространства;
- **Схема программатора для каждой микросхемы –** принципиальная схема программатора для каждой микросхемы памяти отображается на отдельной вкладке при выборе соответствующего типа микросхемы;
- **Кроссплатформенность –** поддержка наиболее распространенных ОС, таких как Windows и Linux (Версия для MacOS пока не рассматривается, так как LPT порт присутствует только на оооочень старых Mac&#39;ах).

Версия для Linux пока не совсем доработанная и графический интерфейс неправильно форматирован, как на рисунках ниже, из-за отличий в шрифтах и прочем;

![](/README.image/1.bmp)

Версия для Linux

![](/README.image/2.bmp)

Версия для Windows

**Список изначально поддерживаемых микросхем программатором**  **UPROG**  **версии 1.0:**

**Фирма**  **ATMEL:**

- AT17LV(C)65A
- AT17LV(C)128A
- AT17LV(C)256A
- AT17LV(C)512A
- AT17LV(C)010A
- AT17LV(C)002A
- AT17LV(C)040A

В следующих версиях список изначально поддерживаемых микросхем памяти будет пополняться. Также необходимо сделать загрузку уже откомпилированных пользовательских динамических библиотек DLL посредством метода _LoadLibrary_ без перекомпиляции всего проекта.

**Минимальные системные требования для программатора**  **UPROG**  **версии 1.0:**

- Операционная система: Windows (начиная с XP), Linux с графической оболочкой MATE, Cinnamon и прочие;
- Дополнительно ПО: **Python версии только 2.7 x86** https://www.python.org/downloads/release/python-2717/; **Qt (Qt Creator) версии только 5.0.2** https://download.qt.io/official_releases/qtcreator/5.0/5.0.2/
- Процессор: x86 233 МГц Pentium II
- Память ОЗУ: 128 Мбайт
- Память ПЗУ: 50 Мбайт свободного места на диске

В следующих версиях, возможно, появится совместимость с ещё более старыми версиями ОС, такими как Windows 95 и Windows 98, а, соответственно, совместимость с более старыми процессорами архитектуры x86, начиная с процессора 80386.

Если будет возможно, то, когда-нибудь, UPROG можно будет запустить под MS-DOS. Думаю, что модульность программы позволит это сделать с некоторыми ограничениями.

Также, желательна, в дальнейшем, поддержка архитектуры ARM.

**Инструкция**

Рассмотрим, в качестве обучающего примера, процесс прошивки микросхемы AT17LV010 под ОС Windows.

Запустим UPROG\_Release.bat из папки _Deploy __/__ Windows __/__ msvc __\_2010\___ qt__\_5\_0\_2/_

Запустится окно программы:

![](/README.image/3.bmp)

Далее можно активировать дополнительное меню с помощью клавиши _Ctrl_:

![](/README.image/4.bmp)

При нажатии на ссылку в разделе &quot;Производитель&quot; (подчеркнутый пункт выпадаюшего списка меню) откроется браузер с сайтом производителя (либо откроется файл с его описанием, хранящийся на жестком диске, если таковой будет задан в JSON файле).

При нажатии на ссылку в разделе &quot;Микросхема&quot; можно перейти на сайт с документацией на микросхему либо откроется документация на жестком диске, если таковая указана в JSON файле.

При нажатии на ссылку в разделе &quot;Программатор&quot; будет осуществлен переход на вкладку с принципиальной схемой программатора:

![](/README.image/5.bmp)

Либо, если файл со схемой не задан в JSON файле, то откроется подобная вкладка:

![](/README.image/6.bmp)

Чтобы открыть схему во вкладке в полном размере, необходимо нажать на _Ctrl_(дополнительное меню) и нажать на схему. В этом случае откроется картинка средствами системного просмоторщика картинок.

Вернемся обратно к первой вкладке. Выберем производителя _Atmel_из списка:

![](/README.image/7.bmp)

Данный список формируется посредством чтения JSON файлов из папки _json_.

Далее выберем микросхему AT17LV010 из списка:

![](/README.image/8.bmp)

Данный список также формируется посредством чтения JSON файлов для данного производителя из папки _json_.

Далее выберем программатор из списка:

![](/README.image/9.bmp)

Данный список также формируется посредством чтения JSON файлов для данных производителя и микросхемы из папки _json_. В данном случае программатор LPT\_I2C означает протокол I2C поверх интерфейса LPT (параллельный порт).

Выбрав необходимые нам микросхему и программатор, настроим программатор:

![](/README.image/10.bmp)

Для этого заменим адрес 0378 на свой (в данном случае D050). Адрес LPT порта в Windows можно посмотреть в Диспетчере устройств в свойствах контроллера LPT:

![](/README.image/26.bmp)

Далее, необходимо нажать Enter, чтобы параметры установились, ранее поле, ставшее красным, должно стать белым:

![](/README.image/11.bmp)

Настроив программатор, настроим параметры конфигурационной памяти для программируемой микросхемы. К примеру, установим параметр RESET в 1. Для этого необходимо нажать на значок фигурных скобок соответствующего поля, чтобы там появился крестик.

Для данной микросхемы, сигнал RESET установленный в 1 значит, что наша микросхема будет сбрасываться по сигналу RESET высокого уровня, а активный уровень сигнала OE будет низким.

После того как все параметры настроены, можно приступать к записи прошивки. Для этого необходимо нажать на кнопку запись:

![](/README.image/12.bmp)

После чего откроется окно предупреждения, что параметры LPT порта заданы верно:

![](/README.image/13.bmp)

После нажатия на Да (Yes), откроется окно выбора файла прошивки, где необходимо будет найти и открыть файл существующего формата:

![](/README.image/14.bmp)

Если нажать на Отмену (Cancel), то появится диалоговое окно с предложением стереть память микросхемы:

![](/README.image/15.bmp)

Если файл открыть, то появится сообщение о том, что питание подано и сигналы установлены в начальное состояние:

![](/README.image/16.bmp)

После утвердительного ответа, программатор попытается считать информацию с микросхемы, такую как, например, код производителя и выведет результат, если код производителя отличается:

![](/README.image/17.bmp)

В нашем случае, все байты равны 0xFF. Это должно насторожить, поскольку хотя бы какие-нибудь из первых 2-х байтов должны быть не 0xFF. Это может означать, что микросхема не определяется. Однако, так может быть даже когда микросхема определилась, но код производителя по каким-то причинам, был стёрт.

Чтобы проверить, что микросхема определяется, отвечаем утвердительно и смотрим результат. Если микросхема не определяется, то появится следующее окно:

![](/README.image/18.bmp)

Если микросхема нормально определилась и отвечает на запросы, то откроется вкладка с HEX таблицей памяти микросхемы и процессом прошивки в реальном времени:

![](/README.image/19.bmp)

<span style="color:green">**Зеленая**</span> индикация проводника показывает, что данные байты были уже записаны в память. <span style="color:red">**Красная**</span> индикация проводника показывает, что этот байт в процессе записи в память. <span style="color:orange">**Оранжевая**</span> индикация проводника означает, что данные байты ожидают записи.

Процесс записи также отображается в правом нижнем углу в процентах.

В любой момент можно прервать как запись так и чтение нажатием на клавишу ESC:

![](/README.image/20.bmp)

Данное окошко также отображается по завершении процесса записи (стирания) или чтения.

Чтобы убедиться, что данные записались верно, необходимо произвести чтение из памяти микросхемы:

![](/README.image/21.bmp)

Далее, всё аналогично процессу записи. Выбираем файл прошивки для сохранения:

![](/README.image/22.bmp)

Если нажать Отмена (Cancel), то вылезет следующее окно:

![](/README.image/23.bmp)

После утвердительного ответа, прошивка будет считана без сохранения её в файл. Индикация процесса чтения аналогична, только считанные байты появляются в HEX таблице <span style="color:green">**зеленым цветом**</span> вместо 0xFF по мере чтения.

![](/README.image/24.bmp)

В версии для Linux все операции аналогичны. Единственный нюанс – **запускать программу надо с использованием**  **SUDO**  **!!!** Иначе не будет работать LPT порт.

Другой особенностью версии для Linux является её недоработанность. Графический интерфейс и функционал может отличаться от версии под Windows:

![](/README.image/25.bmp)

В следующих версиях многое будет исправлено, надеюсь…

Адрес LPT порта в Linux можно получить с помощью команды _lspci_, если LPT порт присутствует в виде карты расширения на шине PCI или PCI-Express, либо с помощью команды _lshw_, если LPT порт уже стоит на плате.

<<<<<<< HEAD
**UPDATE:** � ����� Device/PatternMan/PatternDev ���������� ������ ��� ���������� ����������������� ���������� 
=======
Видео с работой [![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/YOUTUBE_VIDEO_ID_HERE/0.jpg)](https://www.youtube.com/watch?v=YOUTUBE_VIDEO_ID_HERE)


**UPDATE:** в папке Device/Pattern расположен шаблон для библиотеки пользовательского устройства 
>>>>>>> 59a5301493b148c18f4612f1da862d05f64a6655
