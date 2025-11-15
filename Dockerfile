FROM ubuntu:22.04

# Install system dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    wget \
    libxt-dev libx11-dev libxext-dev \
    libpng-dev libjpeg-dev && \
    rm -rf /var/lib/apt/lists/*

# Install Matplot++ in a separate layer for better caching
# This layer will only rebuild if Matplot++ installation changes
RUN git clone --depth=1 --single-branch --branch master \
    https://github.com/alandefreitas/matplotplusplus.git /tmp/matplotplusplus && \
    cd /tmp/matplotplusplus && \
    mkdir build && cd build && \
    cmake .. \
    -DBUILD_EXAMPLES=OFF \
    -DBUILD_TESTS=OFF \
    -DCMAKE_INSTALL_PREFIX=/usr/local \
    -DCMAKE_BUILD_TYPE=Release && \
    make -j$(nproc) && \
    make install && \
    ldconfig && \
    rm -rf /tmp/matplotplusplus

# Set environment variables
ENV LD_LIBRARY_PATH=/usr/local/lib
ENV CMAKE_PREFIX_PATH=/usr/local
ENV PKG_CONFIG_PATH=/usr/local/lib/pkgconfig

# Set working directory
WORKDIR /app

# Copy project files (this happens after Matplot++ is installed and cached)
COPY . .

# Build the project
RUN rm -rf build && \
    mkdir build && \
    cd build && \
    cmake .. -DCMAKE_PREFIX_PATH=/usr/local && \
    make -j$(nproc)

CMD ["./build/UC_Addmission_Trends"]