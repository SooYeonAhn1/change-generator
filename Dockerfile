FROM ubuntu:22.04 AS builder

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git

WORKDIR /app

COPY . .
COPY CMakeLists.txt .

RUN cmake . && make

FROM ubuntu:22.04

WORKDIR /app

COPY --from=builder /app/cg.out .

CMD ["./cg.out"]
