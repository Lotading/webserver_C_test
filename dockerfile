FROM archlinux:latest AS BUILDER
RUN pacman -Sy --noconfirm gcc
COPY . /app
WORKDIR /app
RUN gcc server.c -o server

FROM archlinux:latest AS LAUNCH
COPY --from=BUILDER /app/server /app/server
WORKDIR /app
EXPOSE 8080
CMD ["./server","public/index.html"]