FROM ubuntu:latest
# Update package manager
RUN apt-get update
# Install build-essential package for g++
RUN apt-get install -y build-essential
# Install clang
RUN apt-get install -y clang
# Set up clang as the default compiler
RUN update-alternatives --install /usr/bin/cc cc /usr/bin/clang 100
RUN update-alternatives --install /usr/bin/c++ c++ /usr/bin/clang++ 100

COPY . /urs/src/clang_run_file_cpp

WORKDIR /urs/src/clang_run_file_cpp

RUN clang++ -o file_run hello.cpp

CMD [ "./file_run" ]