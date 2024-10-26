// kernel.c
void main() {
    const char *str = "Hello World!";
    char *video_memory = (char *)0xb8000; // Starting address of VGA text buffer
    for (int i = 0; str[i] != '\0'; i++) {
        video_memory[i * 2] = str[i];        // Character
        video_memory[i * 2 + 1] = 0x07;      // Attribute byte: light grey on black background
    }
    while (1); // Infinite loop to keep the OS running
}
