FROM ubuntu:18.04

LABEL maintainer="Shkuran <Group 231-3210>"

RUN apt-get update && apt-get install -y \
    gcc \
    qt5-default \
    build-essential

WORKDIR /MyProj_231-3210_Shkuran

COPY . .

RUN qmake MyDB.pro
RUN make

RUN mv MyDB exam_program.exe

ENV PROGRAM_PARAM=default_value

CMD ./exam_program.exe ${PROGRAM_PARAM}
