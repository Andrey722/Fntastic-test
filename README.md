# Fntastic-test
Срок выполнения до 5 дней.
Электронная почта для связи: job@fntastic.com
По любым вопросам можете писать на почту с пометкой “UE4 Developer” и указанием вашего ФИО и ссылки на резюме.
Решение отправляйте ссылкой на ваш репозиторий (гитхаб или гитлаб), он должен быть публичный.
Обратите внимание на вес проекта, он не должен превышать 300 мегабайт.
Решение рассматривается в течении 3-4 рабочих дней.

## Fntastic-1

1) Задание можно решить на любом языке программирования.
Цель - конвертировать исходную строку, в новую строку, где каждый символ заменяется на символ “ ( ”, если символ встречается только один раз или на “ ) “, если символ встречается больше одного раза. При решении программа должна игнорировать заглавные буквы, при определении дубликатов (т.е. “А” и “а” - это один и тот же символ).
Пример входных и выходных данных:

- "din"      =>  "((("

- "recede"   =>  "()()()"

- "Success"  =>  ")())())"

- "(( @"     =>  "))(("


## Fntastic-2

2) Необходимо выполнить задание на Unreal Engine 4.26. Реализация должна быть в 3D. Все ассеты (модели, звуки, текстуры), кроме кода и блюпринтов, можете брать из любых источников. Необходимо использовать принципы ООП, соблюдать стилизацию кода, блюпринты должны быть удобочитаемыми. Использовать сторонние плагины нельзя.

- Есть сцена с тремя кнопками, которые называются “1”, “2” и “3”.
- На сцене расположены три “гнезда”: “гнездо-1”, “гнездо-2” и “гнездо-3”. Подразумевается, что из гнезд могут появиться черепашки.
- У каждого “гнезда” есть своя точка назначения.
- При нажатии кнопки “1” в “гнезде-1” появляется “черепашка-1”, которая должна прийти в движение и пройти от своей позиции вперед, до точки назначения.
- При нажатии кнопки “2” в “гнезде-2” появляется “черепашка-2”, которая должна прийти в движение и тоже пройти от своей позиции до точки назначения, но по таким правилам: идет секунду вперед и на полсекунды останавливается, опять идет секунду вперед и на полсекунды останавливается, и т.д.
- При нажатии кнопки “3” в “гнезде-3” появляется “черепашка-3”, которая, тоже, должна начать движение до точки назначения, но по таким правилам: идет секунду вперед и затем полсекунды назад, опять секунду вперед и полсекунды назад, и т.д.
- Необходимы аудио-эффекты и визуальные эффекты при появлении, передвижении и финишировании “черепашек”. Эффекты выбираются на ваше усмотрение.
- При запуске проекта, должен открываться уровень, на котором реализовано тестовое задание.
