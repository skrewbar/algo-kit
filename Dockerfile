FROM ubuntu

WORKDIR /algo-kit

RUN apt-get update \
    && apt-get install -y git gcc-14 g++-14 gdb clangd clang-format pypy3 python3 python3-pip python3-venv \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-14 100 \
    && update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-14 100 \
    && update-alternatives --set gcc /usr/bin/gcc-14 \
    && update-alternatives --set g++ /usr/bin/g++-14

RUN python3 -m venv /usr/local/venv \
    && /usr/local/venv/bin/pip install --upgrade pip \
    && /usr/local/venv/bin/pip install pre-commit

COPY entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh

CMD ["entrypoint.sh"]
