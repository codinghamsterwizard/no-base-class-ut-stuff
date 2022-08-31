#ifndef MOCKABLE_H
#define MOCKABLE_H

#ifndef MOCKABLE
#ifndef UNIT_TEST
#define MOCKABLE(type) type
#else
#define MOCKABLE(type) type##_mock
#endif // UNIT_TEST
#else
#error MOCKABLE is defined elsewhere
#endif // MOCKABLE

#ifndef MOCKABLE_PRIVATE
#ifndef UNIT_TEST
#define MOCKABLE_PRIVATE private
#else
#define MOCKABLE_PRIVATE public
#endif // UNIT_TEST
#else
#error MOCKABLE_PRIVATE is defined elsewhere
#endif // MOCKABLE_PRIVATE

#endif // MOCKABLE_H
