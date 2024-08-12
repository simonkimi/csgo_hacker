

namespace hackerlib {


class HandleRaii {
public:
    explicit HandleRaii(HANDLE handle);

    HandleRaii(const HandleRaii &) = delete;

    HandleRaii &operator=(const HandleRaii &) = delete;

    HandleRaii(HandleRaii &&other) noexcept = default;

    HandleRaii &operator=(HandleRaii &&other) noexcept = default;

    ~HandleRaii();

    [[nodiscard]] HANDLE get() const;

    [[nodiscard]] bool isInvalid() const;

private:
    HANDLE handle_;
};

}

