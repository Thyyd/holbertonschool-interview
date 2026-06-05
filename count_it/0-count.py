#!/usr/bin/python3
"""
Module for counting word occurrences in Reddit hot posts
"""
import requests


def count_words(subreddit, word_list, after=None, word_count=None):
    """
    Recursively queries Reddit API and counts keyword occurrences
    in hot article titles.

    Args:
        subreddit: subreddit name to query
        word_list: list of keywords to count
        after: pagination token for Reddit API
        word_count: dictionary tracking word counts
    """
    if word_count is None:
        # Initialize word_count dict with lowercase keys
        word_count = {}
        for word in word_list:
            word_lower = word.lower()
            word_count[word_lower] = word_count.get(word_lower, 0)

    # Set up headers to avoid rate limiting
    headers = {'User-Agent': 'Mozilla/5.0'}

    # Build URL with pagination
    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    params = {'limit': 100, 'after': after}

    try:
        # Make request without following redirects
        response = requests.get(url, headers=headers, params=params,
                                allow_redirects=False)

        # Check if subreddit is invalid (redirect or not found)
        if response.status_code != 200:
            return

        data = response.json()
        posts = data.get('data', {}).get('children', [])

        # If no posts, we're done
        if not posts:
            # Print results only on first call (when after is None initially)
            if after is None:
                print_results(word_count)
            return

        # Count words in current batch of titles
        for post in posts:
            title = post.get('data', {}).get('title', '').lower()
            words_in_title = title.split()

            for word in words_in_title:
                # Clean word: remove non-alphanumeric chars
                clean_word = ''.join(c for c in word if c.isalnum())
                if clean_word in word_count:
                    word_count[clean_word] += 1

        # Get next page token
        after = data.get('data', {}).get('after')

        # Recursive call for next page
        if after is not None:
            count_words(subreddit, word_list, after, word_count)
        else:
            # We're done, print results
            print_results(word_count)

    except Exception:
        return


def print_results(word_count):
    """
    Prints word counts in descending order by count,
    then alphabetically for ties.

    Args:
        word_count: dictionary of word counts
    """
    # Filter out words with 0 count
    filtered = {k: v for k, v in word_count.items() if v > 0}

    if not filtered:
        return

    # Sort by count (descending) then alphabetically (ascending)
    sorted_words = sorted(filtered.items(),
                          key=lambda x: (-x[1], x[0]))

    for word, count in sorted_words:
        print(f"{word}: {count}")
