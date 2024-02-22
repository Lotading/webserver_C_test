FROM archlinux:latest AS BUILDER
RUN pacman -Sy --noconfirm gcc make
COPY . /app
WORKDIR /app
RUN make

FROM archlinux:latest AS LAUNCH
COPY --from=BUILDER /app/server /app/server
WORKDIR /app
EXPOSE 8080
CMD ["./server","/"]