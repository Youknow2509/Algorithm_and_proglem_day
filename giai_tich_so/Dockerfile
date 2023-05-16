FROM gcc:latest

WORKDIR /app

COPY pp_chia_doi.cpp /app
COPY Show_screen/INP.TXT /app
COPY Show_screen/OUT.TXT /app

RUN g++ -o myapp pp_chia_doi.cpp

CMD ["./myapp"]
