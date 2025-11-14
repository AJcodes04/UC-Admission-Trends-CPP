FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    wget \
    libxt-dev libx11-dev libxext-dev \
    libpng-dev libjpeg-dev && \
    rm -rf /var/lib/apt/lists/*

RUN git clone https://github.com/alandefreitas/matplotplusplus.git /opt/matplotplusplus && \
    cd /opt/matplotplusplus && mkdir build && cd build && \
    cmake .. && make -j$(nproc) && make install


WORKDIR /app

COPY . .

RUN rm -rf build && mkdir build && cd build && cmake .. && make -j$(nproc)


CMD ["./build/UCTrends"]