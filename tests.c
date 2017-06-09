#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "sha2.h"


const char MESSAGE1[] = "abc";
const char MESSAGE2[] = "abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq";

const char MESSAGE3[1000000] = "";


const char MESSAGE1_SHA256_HASH[] = "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad";
const char MESSAGE2_SHA256_HASH[] = "248d6a61d20638b8e5c026930c3e6039a33ce45964ff2167f6ecedd419db06c1";
const char MESSAGE3_SHA256_HASH[] = "cdc76e5c9914fb9281a1c7e284d73e67f1809a48a497200e046d39ccc7112cd0";


void test256(const char* message, const char* result, unsigned int digestSize) {

	unsigned char digest[digestSize];

	sha256((unsigned char*)message, strlen(message), digest);

	for (unsigned int i=0; i<digestSize; i++) {

		unsigned int value;
		sscanf(result+i*2, "%02x", &value);

		CAPTURE(i);
		CHECK(digest[i] == value);
	}
}


TEST_CASE("SHA-256 scenario") {

	SUBCASE("Message 1") {
		test256(MESSAGE1, MESSAGE1_SHA256_HASH, SHA256_DIGEST_SIZE);
	}

	SUBCASE("Message 1") {
		test256(MESSAGE2, MESSAGE2_SHA256_HASH, SHA256_DIGEST_SIZE);
	}

	printf("%d\n", (int)strlen(MESSAGE3));
}
